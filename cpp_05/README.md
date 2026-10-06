*This project has been created as part of the 42 curriculum by lseabra-.*

# C++ - Module 05

## Description

This module introduces exceptions and uses them to enforce rules in a small
bureaucratic system. It begins with grade validation, then adds forms that can
be signed and executed, concrete forms with distinct actions, and an Intern
that creates forms by name.

In this module, you will learn:
- how to define exception types by deriving from `std::exception`;
- how to validate object state during construction and operations;
- how `const` members affect copy assignment;
- how to report success or failure through overloaded stream output;
- how polymorphic forms share validation and execution behavior;
- how concrete classes provide the action required by an abstract base;
- how a factory can return a concrete object through a base-class pointer.

The module is about contracts and failure paths:
- Which grades are valid, and which grade is sufficient for an operation?
- What state changes when a form is signed?
- What conditions must hold before a form can execute?
- Who owns the object returned by a factory?

### The module has 4 exercises:

| Exercise | Name | Topics | Description |
|---|---|---|---|
| ex00 | Bureaucrat | exceptions, grade boundaries, stream output | Implement a Bureaucrat whose grade must remain between 1 and 150. |
| ex01 | Form up, maggots! | validation, signing, immutable attributes | Add Forms that validate required grades and can be signed by eligible Bureaucrats. |
| ex02 | No, you need form 28B, not 28C... | abstract classes, polymorphism, file output, random outcomes | Add executable forms for shrubbery creation, robotomy requests, and presidential pardons. |
| ex03 | At least this beats coffee-making | factory functions, dispatch tables, dynamic ownership | Add an Intern that creates one of the three concrete forms from its name. |

## The story arc of the module

The central challenge is to make invalid operations explicit and keep each
class responsible for its own rules. A Bureaucrat validates grades; a Form
validates its required grades and signing state; concrete forms perform their
own actions only after the shared execution checks pass.

The final exercise moves form selection behind an Intern. The caller asks for
a form by name and receives an `AForm*`, without needing to know the concrete
class at the creation call site. That pointer owns a dynamically allocated
form, so the caller must eventually delete it.

### ex00: Bureaucrat

**Goal**: Represent a Bureaucrat with a valid grade and report grade errors.

**What the exercise is about**:
- Store an immutable name and a mutable grade from 1 (highest) to 150
  (lowest).
- Throw `GradeTooHighException` when a grade would be below 1 and
  `GradeTooLowException` when it would be above 150.
- Apply the same boundaries in the constructor, `incrementGrade()`, and
  `decrementGrade()`.
- Overload `operator<<` to display the Bureaucrat's name and grade.
- Use nested exception classes derived from `std::exception`.

### ex01: Form up, maggots!

**Goal**: Let Bureaucrats sign Forms only when their grade is high enough.

**What the exercise is about**:
- Give each Form an immutable name and required signing and execution grades,
  plus a mutable signed flag.
- Reject required grades outside the valid 1-to-150 range.
- Make `beSigned()` throw `GradeTooLowException` when the Bureaucrat is not
  senior enough; otherwise, mark the Form signed.
- Add `Bureaucrat::signForm()` to attempt signing and report the outcome.
- Overload `operator<<` to display the Form's state and grade requirements.

The execution grade is part of the Form's data in this exercise; actual form
execution is added in ex02.

### ex02: No, you need form 28B, not 28C...

**Goal**: Make forms executable while keeping authorization checks in a shared
abstract base class.

**What the exercise is about**:
- Replace `Form` with abstract `AForm`, which owns the common signing state and
  required grades.
- Require a Bureaucrat to sign a form before it can execute, and require the
  executor to meet the form's execution grade.
- Implement `ShrubberyCreationForm` (sign grade 145, execute grade 137), which
  writes a tree to `<target>_shrubbery` in the current working directory.
- Implement `RobotomyRequestForm` (72, 45), which reports the drilling sound
  and a randomized success or failure.
- Implement `PresidentialPardonForm` (25, 5), which reports a pardon by
  Zaphod Beeblebrox.
- Keep the common execution checks in `AForm::execute()` and dispatch the
  concrete action polymorphically.

The concrete forms override the inherited virtual `action()` function. They do
not need to redeclare every other virtual function: a concrete class inherits
an implementation when its base already provides one. It only needs to
override a virtual function when it supplies different behavior or completes
an inherited pure virtual requirement.

### ex03: At least this beats coffee-making

**Goal**: Create concrete forms by name without exposing their concrete types
to the caller.

**What the exercise is about**:
- Match the requested name against the three supported form names.
- Use a table of names and creation functions to construct the right form.
- Return the new object as an `AForm*` and report the successful creation.
- Throw `UnknownFormException` when no form name matches.
- Delete the returned pointer when the caller is finished with the form.

`makeForm()` transfers responsibility for the returned allocation to its
caller. Because the pointer refers to an `AForm`, its virtual destructor makes
deletion through that base pointer safe. If the call throws, no form pointer is
returned to own or delete.

Together, the exercises build from local validation rules to polymorphic
behavior and dynamic object creation. The key questions are what state an
operation may change, which checks must pass first, and who is responsible for
an object after it has been created.

## Instructions

### Requirements

- Compile with `c++` and the flags `-Wall -Wextra -Werror`.
- Code must still compile with `-std=c++98`.
- Class names use `UpperCamelCase`; class files are named after their classes.
- Header files must be self-contained and protected by include guards.
- No implementations belong in headers, except function templates.
- Forbidden: `*printf()`, `*alloc()`, `free()`, `using namespace ...`, and
  `friend`.
- STL containers and `<algorithm>` are forbidden until Modules 08 and 09.
- From Module 02 onward, classes follow the Orthodox Canonical Form unless
  the subject explicitly says otherwise.
- Every exercise should be tested at both valid boundaries and failure paths.

### How to Run

Build and run an exercise from its directory:

```bash
cd cpp_05/ex00
make
./bureaucrat
```

Each exercise has its own `bureaucrat` executable. In ex01, ex02, and ex03,
passing `-a` also runs the additional Bureaucrat and/or form test groups:

```bash
./bureaucrat -a
```

The Makefiles support:
- `make` or `make all`: build the executable;
- `make re`: remove generated files and rebuild;
- `make clean`: remove object files;
- `make fclean`: remove object files and the executable.

Some tests perform file output. In ex02 and ex03, a successful shrubbery form
creates `<target>_shrubbery` in the current working directory. Run the program
from a disposable directory if you do not want generated files beside the
source.

## Core Concepts

### Exceptions as Contracts

An exception communicates that an operation cannot satisfy its contract. A
constructor rejects an invalid initial grade; grade changes reject crossing
the valid range; signing and execution reject insufficient authorization.
Nested exception classes keep errors associated with the class that defines
the relevant rule.

Catch exceptions by reference, preferably as `const std::exception&` when the
specific derived type is not needed. Catch a specific exception first when
different failures need different handling.

### Grade Ordering

Grades are inverse to ordinary numeric intuition: grade 1 has the most
authority, while grade 150 has the least. A Bureaucrat with grade `b` meets a
required grade `r` when `b <= r`. Equality is sufficient; the boundary grade
must not be rejected.

### Signing and Execution

Signing and execution are separate operations. `beSigned()` changes the Form's
signed state only when the sign-grade check succeeds. In ex02 and ex03,
`AForm::execute()` first rejects an unsigned form, then checks the executor's
grade, and only then calls the concrete action. Keeping these preconditions in
the base class prevents each derived form from implementing authorization
differently.

### Const Members and Assignment

The name and required grades are `const` because they define a Form's identity
and authorization policy. Assignment cannot replace those members after
construction. The assignment operator can copy mutable state, such as the
signed flag; derived forms can additionally copy their target. This distinction
is expected behavior for these classes, not a failed copy.

### Abstract Forms and Overrides

`AForm` is abstract because `action()` is pure virtual. A derived class is
concrete once it provides that missing implementation. Other virtual functions
with concrete base implementations are inherited normally; they do not need to
be repeated in each derived class unless the derived behavior differs.

`AForm` also has a virtual destructor, allowing a concrete form to be destroyed
through an `AForm*`.

### Factory Functions and Ownership

The Intern's recipe table associates each supported name with a creation
function. `makeForm()` calls the matching function and returns the allocated
object through the base type. The caller owns the returned pointer and must
delete it exactly once. A successful factory call should therefore be paired
with cleanup, including when later operations on the form fail.

An unknown name has no matching recipe and results in `UnknownFormException`.
This makes the unsupported request an explicit failure instead of returning an
ambiguous null pointer.

## Common Pitfalls

### Reversing Grade Comparisons
The smaller number is the higher grade. A check using `>` for “high enough”
will reverse authorization and accept the wrong Bureaucrats.

### Off-by-One Boundaries
Grades 1 and 150 are valid. Only an operation that would move beyond those
limits should throw; a Bureaucrat exactly at a Form's required grade is
eligible.

### Signing Without Checking the Result
`Bureaucrat::signForm()` reports the outcome, while `Form::beSigned()` or
`AForm::beSigned()` performs the state change or throws. A failed attempt must
leave the Form unsigned.

### Executing Before Both Checks
An unsigned form must not perform its action. A signed form must still reject
an executor whose grade is too low. Put these checks before dispatching to
`action()`.

### Leaking a Factory Result
`makeForm()` returns a dynamically allocated object. Store the returned pointer
and delete it after use; do not lose it if signing or execution can throw.

### Assuming `rand()` Is Seeded
`rand()` produces a pseudo-random sequence. Without a call to `srand()`, a
program commonly begins with the same sequence on each run. The robotomy
exercise requires a random outcome, not a cryptographic one.

## References

- [cppreference.com - Exceptions](https://en.cppreference.com/w/cpp/language/exceptions)
- [cppreference.com - `std::exception`](https://en.cppreference.com/w/cpp/error/exception)
- [cppreference.com - `std::exception::what`](https://en.cppreference.com/w/cpp/error/exception/what)
- [cppreference.com - Virtual functions](https://en.cppreference.com/w/cpp/language/virtual)
- [cppreference.com - Abstract classes](https://en.cppreference.com/w/cpp/language/abstract_class)
- [cppreference.com - `std::ofstream`](https://en.cppreference.com/w/cpp/io/basic_ofstream)
- [cppreference.com - `std::rand`](https://en.cppreference.com/w/cpp/numeric/random/rand)
- [cppreference.com - `std::srand`](https://en.cppreference.com/w/cpp/numeric/random/srand)
- [Microsoft - Exception-handling statements - `throw`, `try-catch`, `try-finally`, and `try-catch-finally`](https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/statements/exception-handling-statements)
- [GeeksforGeeks - Exception Handling in C++](https://www.geeksforgeeks.org/cpp/exception-handling-c/)

## AI Usage

AI was used to:
- help structure and proofread this README;
- tutor me on core concepts and design trade-offs; and
- guide me in following best practices for exception handling.

The exercise descriptions and implementation details were checked against the local `SCRATCH.md`, headers, source files, and Makefiles.

## Final Reflection

Module 05 connects exception handling to object design. Grade checks and form
preconditions turn rules into enforceable contracts, while polymorphism lets
different forms provide their own actions through one shared interface. The
Intern adds a final layer: callers request a form by name, but still need to
understand who owns the created object and when it must be released.

The progression from ex00 to ex03 moves from protecting one integer invariant
to coordinating validation, state, dynamic dispatch, and ownership. Good
exception handling does more than print an error; it preserves object state
and gives the caller a clear way to respond to failure.