*This project has been created as part of the 42 curriculum by lseabra-.*

# C++ - Module 04

## Description

This module introduces subtype polymorphism, abstract classes, and interfaces.
It builds on inheritance from Module 03 and focuses on the difference between a
class's static type and the dynamic type of the object it refers to.

In this module, you will learn:
- how virtual functions select the most-derived implementation at runtime;
- why polymorphic base classes need virtual destructors;
- how to implement deep copy when a class owns dynamically allocated state;
- how pure virtual functions make a class abstract;
- how pure abstract classes are commonly used as interfaces in C++98;
- how to model ownership explicitly when classes exchange polymorphic pointers.

The module is about contracts and lifetime:
- When should a base member function be virtual?
- Who owns an object passed through a base-class pointer?
- How can a copy preserve behavior without sharing owned resources?
- How do interfaces express behavior without providing a concrete object?

### The module has 4 exercises:

| Exercise | Name | Topics | Description |
|---|---|---|---|
| ex00 | Polymorphism | virtual functions, virtual destructors | Build Animal, Dog, Cat, WrongAnimal, and WrongCat to observe dynamic dispatch. |
| ex01 | I don't want to set the world on fire | composition, dynamic ownership, deep copy | Add a Brain to Dog and Cat and manage polymorphic animals without leaks. |
| ex02 | Abstract class | pure virtual functions | Make Animal abstract so it cannot be instantiated directly. |
| ex03 | Interface & recap | interfaces, cloning, ownership, deep copy | Implement AMateria, Character, Ice, Cure, and MateriaSource. |

## The story arc of the module

The central challenge of this module is learning that runtime polymorphism is
only useful when object lifetime and ownership are correct. The exercises
explore how a common interface can support different concrete behaviors, how
resources survive copying, and how abstract classes prevent invalid designs.

### ex00: Polymorphism

**Goal**: Demonstrate dynamic dispatch and the need for virtual destructors.

**What the exercise is about**:
- Store Dog and Cat objects behind `Animal*` pointers.
- Override `makeSound()` so the dynamic type controls the result.
- Compare the correct hierarchy with WrongAnimal and WrongCat, where the
  non-virtual function prevents dynamic dispatch.
- Delete derived objects through base pointers and verify destructor behavior.

### ex01: I don't want to set the world on fire

**Goal**: Manage owned dynamic state in a polymorphic hierarchy.

**What the exercise is about**:
- Give every Dog and Cat a dynamically allocated Brain containing 100 ideas.
- Release the Brain in the derived destructor.
- Implement the Orthodox Canonical Form without shallow-copying the Brain.
- Delete a mixed array of animals through `Animal*` and verify the complete
  destructor chain.

### ex02: Abstract class

**Goal**: Prevent meaningless Animal instances.

**What the exercise is about**:
- Make Animal abstract with a pure virtual `makeSound()`.
- Keep Dog and Cat concrete by overriding the pure virtual function.
- Preserve polymorphic deletion through the virtual Animal destructor.

### ex03: Interface & recap

**Goal**: Combine interfaces, polymorphic cloning, fixed-size inventories, and
deep-copy ownership.

**What the exercise is about**:
- Use pure abstract classes as C++98 interfaces.
- Store heterogeneous `AMateria` objects behind base pointers.
- Implement Ice and Cure with polymorphic `clone()` and `use()` behavior.
- Make Character own at most four Materias and deep-copy them.
- Make MateriaSource store at most four cloned templates and create new clones
  by type.
- Handle unknown types, invalid indexes, capacity limits, copy assignment, and
  ownership transfers without leaks.

Together, the exercises develop a practical understanding of subtype
polymorphism, abstract interfaces, deep copying, and explicit ownership. The
important question is not only which function runs, but also which object owns
each resource and exactly when that resource is destroyed.

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
- Every allocation performed with `new` must have a clear owner and must be
  released exactly once.
- From Module 02 onward, classes follow the Orthodox Canonical Form unless the
  subject explicitly says otherwise.
- Every exercise should include more complete tests than the examples in the
  subject.

### How to Run

In each exercise directory, run:

```bash
make
```

The executable name is defined by the `NAME` variable in that exercise's
Makefile. The Makefiles generally support:

- `make` or `make all`: build the executable;
- `make re`: remove generated files and rebuild;
- `make clean`: remove object files;
- `make fclean`: remove object files and the executable.

## Core Concepts

### Subtype Polymorphism

A base pointer or reference can refer to an object of a derived class. When a
member function is virtual, the implementation selected at runtime is the one
belonging to the object's dynamic type, not merely the pointer's static type.

For example, an `Animal*` pointing to a `Dog` calls `Dog::makeSound()` when
`makeSound()` is virtual. Without `virtual`, the call is resolved from the
static type and calls the base implementation instead.

### Virtual Destructors

If a derived object can be deleted through a base pointer, the base destructor
must be virtual. Otherwise, deleting an `Animal*` that points to a Dog may skip
the Dog destructor and leak resources owned by Dog.

The expected destruction order is the reverse of construction: derived
destructor first, then base destructor. This is especially important in ex01,
where Dog and Cat own a dynamically allocated Brain.

### Object Slicing

Polymorphism requires pointers or references. Copying a derived object into a
base object by value copies only the base subobject and slices away the derived
state and behavior. The ex00 and ex01 tests use base pointers so the complete
dynamic object remains intact.

### Abstract Classes

An abstract class has at least one pure virtual function, declared with `= 0`.
It cannot be instantiated directly. Derived classes become concrete only after
implementing every inherited pure virtual function.

In ex02, `Animal` becomes abstract because `makeSound()` is pure virtual. Dog
and Cat provide concrete implementations while remaining usable through
`Animal*`.

### Interfaces in C++98

C++98 has no dedicated interface keyword. A pure abstract class is commonly
used as an interface: it exposes a contract through pure virtual functions and
has no directly constructible implementation.

In ex03, `ICharacter` and `IMateriaSource` define behavior while `Character`
and `MateriaSource` provide the implementation. Their destructors are virtual
so implementations can safely be deleted through interface pointers.

### Clone Pattern

`AMateria::clone()` provides polymorphic copying. A base pointer can be cloned
without knowing whether it points to an Ice, Cure, or another future Materia
type. Character and MateriaSource use this operation to create independent
objects instead of copying only the base subobject.

### Ownership in ex03

The important ownership boundary is the difference between `learnMateria()`
and `equip()`.

#### `learnMateria(AMateria*)`

The subject says that the Materia is copied and stored so it can be cloned
later. This implementation follows that wording literally:

- `MateriaSource` calls `clone()` and stores the clone;
- it does not store or delete the pointer passed by the caller;
- the caller retains ownership of the original pointer whether the source has
  capacity or is already full;
- the caller must delete that original pointer.

The suggested subject main uses `new Ice()` and `new Cure()` without deleting
those arguments, which leaks under this literal copying interpretation. The
suggested main tests were modified to retain the original pointers and delete
them after calling `learnMateria()`.

#### `equip(AMateria*)`

`createMateria()` returns a newly cloned object with no other owner. On a
successful `equip()`, Character stores the pointer and takes responsibility
for deleting it. If the inventory is full or the pointer is null, `equip()` is
a no-op; the caller remains responsible for any non-null pointer rejected by
the Character.

#### `unequip(int)`

`unequip()` clears a slot but never deletes the Materia. The caller must save
the pointer before unequipping and later delete it, or otherwise transfer it
to a new owner. Character only deletes Materias that remain in its inventory
when it is destroyed.

This split keeps ownership explicit and avoids both leaks and double deletes.

## Common Pitfalls

### Missing Virtual Destructors
Deleting through a non-virtual base destructor can skip derived cleanup. Any
base class intended for polymorphic use should have a virtual destructor.

### Shallow Copy of Owned Pointers
Copying a Brain* or AMateria* address creates two owners of one allocation. The
first destructor then leaves the second object with a dangling pointer. Copy
the pointed-to object with its virtual clone operation instead.

### Confusing Static and Dynamic Type
A base pointer does not by itself guarantee dynamic dispatch. The called member
function must be virtual, and the derived class must override it with the same
signature.

## References

- [cppreference.com - virtual function specifier](https://en.cppreference.com/w/cpp/language/virtual)
- [cppreference.com - abstract classes](https://en.cppreference.com/w/cpp/language/abstract_class)
- [cppreference.com - derived classes and virtual bases](https://en.cppreference.com/w/cpp/language/derived_class)
- [cppreference.com - object slicing](https://en.cppreference.com/w/cpp/language/object#Object_slicing)
- [Microsoft Learn - Abstract classes (C++)](https://learn.microsoft.com/en-us/cpp/cpp/cpp/abstract-classes-cpp)
- [GeeksforGeeks - Virtual functions in C++](https://www.geeksforgeeks.org/cpp/virtual-function-cpp/)
- [GeeksforGeeks - Object slicing in C++](https://www.geeksforgeeks.org/cpp/object-slicing-in-c/)
- [GeeksforGeeks - Virtual destructors](https://www.geeksforgeeks.org/cpp/when-to-use-virtual-destructors-in-cpp/)
- [Lei Mao's Log Book - C++ virtual table](https://leimao.github.io/blog/CPP-Virtual-Table/)

## AI Usage

AI was used during this project as a tutor and support tool, specifically for:
- reviewing subtype polymorphism and virtual destructor behavior;
- discussing deep-copy ownership in C++98;
- examining the ambiguity between the `learnMateria()` wording and the suggested main;
- proofreading and restructuring this README.

The implementation decision for `learnMateria()` remains grounded in the
subject's explicit wording: the source clones the argument, and the caller
retains responsibility for the original allocation.

## Final Reflection

Module 04 connects inheritance to real object lifetime. Virtual functions make
one interface support many concrete behaviors, while abstract classes and
interfaces make invalid or incomplete objects harder to create. The harder
part is ownership: every polymorphic pointer needs a clear owner, and every
copy of an owning object must create independent resources.

The progression from ex00 through ex03 turns those ideas into increasingly
concrete designs. By the end of the module, the important question is no
longer only "which function runs?" but also "which object owns this resource,
and exactly when is it destroyed?"
