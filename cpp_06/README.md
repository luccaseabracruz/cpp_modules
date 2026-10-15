*This project has been created as part of the 42 curriculum by lseabra-.*

# C++ - Module 06

## Description

This module explores C++ casts and runtime type information. It starts by
converting scalar literals between `char`, `int`, `float`, and `double`, then
reinterprets a pointer as an integer and back, and finishes by identifying
which derived type a base-class pointer or reference refers to.

In this module, you will learn:
- how to parse numeric strings using C++98 library functions and check errors;
- how to convert between scalar types while detecting impossible or
  non-displayable results;
- how `static_cast`, `reinterpret_cast`, and `dynamic_cast` differ;
- how to represent a pointer value as an integer with `uintptr_t`;
- how pointer and reference forms of `dynamic_cast` report failed casts;
- why runtime type identification needs a polymorphic base class.

The module is about choosing the right conversion and understanding its limits:
- Is the input a valid literal, and can its value fit in the destination type?
- Does a conversion preserve a value, or reinterpret a pointer representation?
- How can a program determine a derived type at runtime?

### The module has 3 exercises:

| Exercise | Name | Topics | Description |
|---|---|---|---|
| ex00 | Conversion of scalar types | parsing, numeric limits, scalar casts | Convert one literal to `char`, `int`, `float`, and `double`. |
| ex01 | Serialization | `reinterpret_cast`, `uintptr_t`, pointers | Convert a `Data*` to an integer representation and back. |
| ex02 | Identify real type | inheritance, RTTI, `dynamic_cast` | Generate an `A`, `B`, or `C` through `Base` and identify its concrete type. |

## The story arc of the module

The first exercise handles conversions from text to values. Parsing and
conversion are separate concerns: the program classifies the literal, parses
it with the appropriate C++98 function, checks for invalid or out-of-range
input, and then prints the four scalar views.

The next exercise moves from numeric values to object addresses. A
`reinterpret_cast` can carry a pointer value through an integer type, but it
does not copy the pointed-to object or make an arbitrary integer a valid
pointer.

The final exercise uses an inheritance hierarchy to identify an object at
runtime. `dynamic_cast` checks the actual object type, with different failure
behavior for pointers and references.

### ex00: Conversion of scalar types

**Goal**: Convert one command-line literal to `char`, `int`, `float`, and
`double`, reporting conversions that are impossible or not displayable.

**What the exercise is about**:
- Keep `ScalarConverter` non-instantiable and expose conversion through its
  static `convert()` function.
- Recognize a single non-digit character, integer and decimal forms, a float
  suffix, and the pseudo-literals `nan`, `+inf`, and `-inf` with their float
  variants.
- Parse integers with `std::strtol` and floating-point values with
  `std::strtod`, checking the end pointer, `errno`, and destination limits.
- Use `std::numeric_limits` to check the ranges of scalar types.
- Print character results as a quoted character, `Non displayable`, or
  `impossible`, then print the integer, float, and double conversions.
- Require exactly one argument and report invalid or out-of-range input.

C++98 does not provide `std::stod`; `std::strtod` is the relevant conversion
function here. Its end-pointer argument identifies where parsing stopped,
which helps distinguish a valid number from trailing invalid text. For
floating-point types, `numeric_limits<T>::min()` is the smallest positive
normalized value, not the most negative value. Use `-numeric_limits<T>::max()`
when checking the lower bound in C++98.

### ex01: Serialization

**Goal**: Convert a `Data*` to `uintptr_t` and deserialize it back to a
`Data*`.

**What the exercise is about**:
- Define a `Data` object with a name and the canonical form operations.
- Provide static `Serializer::serialize()` and `Serializer::deserialize()`
  functions.
- Use `reinterpret_cast` in each direction to preserve the pointer value.
- Check that deserializing the serialized pointer yields the original address
  and still refers to the same object.

Serialization here is an address round trip, not a deep copy or a portable
file format. The integer must be the value produced from the pointer; an
arbitrary integer cannot safely be treated as a valid `Data*`.

### ex02: Identify real type

**Goal**: Generate an instance of one of three derived classes and identify
its type through a `Base*` or `Base&`.

**What the exercise is about**:
- Define a polymorphic `Base` and the derived classes `A`, `B`, and `C`.
- Implement `generate()` to allocate and return one derived instance through a
  `Base*`.
- Use pointer `dynamic_cast` checks in `identify(Base*)`; a failed pointer cast
  returns null.
- Use reference `dynamic_cast` checks in `identify(Base&)`; a failed reference
  cast throws `std::bad_cast`.
- Include a virtual destructor in `Base` so derived objects can be destroyed
  through a base pointer.

The generated object is dynamically allocated. The caller owns the returned
pointer and should delete it when finished. The example uses `std::rand()` and
`std::srand()` with the current time to select a type; this is suitable for a
simple exercise, not for security-sensitive randomness.

Together, the exercises move from checked value conversion to low-level
pointer representation and then to type-safe runtime inspection. The key is
to use each cast only for the kind of conversion it is designed to perform.

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
- Test valid conversions, boundary values, malformed literals, and failed
  runtime casts.

### How to Run

Build and run an exercise from its directory:

```bash
cd cpp_06/ex00
make
./convert 42.0f
```

The other exercises use their own executable names:

```bash
cd cpp_06/ex01
make
./serialize

cd ../ex02
make
./base
```

The Makefiles support:
- `make` or `make all`: build the executable;
- `make re`: remove generated files and rebuild;
- `make clean`: remove the build directory and object files;
- `make fclean`: remove the build directory, object files, and executable.

In ex00, pass exactly one literal as the command-line argument. ex01 and ex02
run their demonstrations without additional arguments.

## Core Concepts

### Parsing and Range Checks

The C conversion functions `std::strtol` and `std::strtod` are available in
C++98. Their end pointer lets the caller detect unparsed characters, while
`errno` can signal range errors. Parsing should be followed by explicit checks
against the destination type's limits before narrowing the value.

For floating-point types, `std::numeric_limits<T>::min()` describes the
smallest positive normalized value. To test the full negative-to-positive
range in C++98, compare against `-std::numeric_limits<T>::max()` and
`std::numeric_limits<T>::max()`.

### Choosing a Cast

`static_cast` performs conversions that are checked by the compiler for
compatibility, including numeric conversions. It does not provide a runtime
check that a base-class object is actually of a requested derived type.

`reinterpret_cast` reinterprets a low-level representation, such as converting
a pointer to `uintptr_t`. It has fewer safety guarantees and should not be
used as a general substitute for a value conversion.

`dynamic_cast` checks a polymorphic object at runtime. A failed cast to a
pointer type returns null; a failed cast to a reference type throws
`std::bad_cast`.

### C++ Core Guidelines: ES.48 and ES.49

ES.48 recommends avoiding casts when the type system or a clearer design can
express the operation instead. For example, prefer virtual dispatch when
behavior depends on an object's dynamic type, rather than repeatedly checking
its type and casting it.

When a cast is necessary, ES.49 recommends using a named C++ cast instead of a
C-style cast. The named form makes the intended operation visible: use
`static_cast` for supported value or related-type conversions,
`reinterpret_cast` only for low-level representation conversions, and
`dynamic_cast` when a checked runtime conversion in a polymorphic hierarchy is
needed. These casts still have different safety guarantees; choosing a named
cast does not make an unsafe conversion safe.

### Pointer Serialization

`uintptr_t`, when provided by the implementation, is an unsigned integer type
capable of holding a converted pointer value. The serialize/deserialize pair
preserves the address for the round trip; it does not serialize the object's
contents or extend the object's lifetime. The original object must still be
alive when the resulting pointer is used.

### Runtime Type Identification

`dynamic_cast` relies on runtime type information and requires a polymorphic
base class, which has at least one virtual function. Here, the virtual
destructor both makes `Base` polymorphic and permits safe destruction through
a `Base*`.

The pointer overload of `identify()` tests derived pointer types without
throwing. The reference overload catches `std::bad_cast` for unsuccessful
checks and continues until it finds the matching type.

## Common Pitfalls

### Treating `stod` as C++98
`std::stod` was introduced in C++11. Use `std::strtod` and inspect its end
pointer and `errno` instead. Compile with `-std=c++98` to catch accidental use
of features from later standards.

### Misreading `numeric_limits::min()`
For floating-point types, `min()` is positive. Use the negated `max()` to
represent the lowest finite bound when checking signed ranges.

### Narrowing Before Checking
Check the parsed value against the destination type's range before casting.
Otherwise, the conversion may lose information or produce an invalid result.

### Confusing Cast Guarantees
`static_cast` does not perform the runtime derived-type check provided by
`dynamic_cast`. `reinterpret_cast` changes how a representation is viewed; it
does not make unrelated types interchangeable or validate a pointer.

### Using a Failed `dynamic_cast` Result
A failed pointer cast produces null, while a failed reference cast throws
`std::bad_cast`. Check the pointer before dereferencing it and catch the
reference exception when probing possible types.

### Losing the Generated Object
`generate()` returns a dynamically allocated object. Keep the returned
`Base*`, use it while the object is alive, and delete it once through the base
pointer when finished.

## References
- [cppreference.com - `static_cast` conversion](https://en.cppreference.com/w/cpp/language/static_cast)
- [cppreference.com - `reinterpret_cast` conversion](https://en.cppreference.com/w/cpp/language/reinterpret_cast)
- [cppreference.com - `dynamic_cast` conversion](https://en.cppreference.com/w/cpp/language/dynamic_cast)
- [C++ Core Guidelines - Avoid casts (ES.48)](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es48-avoid-casts)
- [C++ Core Guidelines - Use named casts (ES.49)](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es49-if-you-must-use-a-cast-use-a-named-cast)
- [GeeksforGeeks - Implicit and Explicit type casting](https://www.geeksforgeeks.org/dsa/implicit-and-explicit-type-casting/)
- [GeeksforGeeks - Type Conversion in C++](https://www.geeksforgeeks.org/cpp/type-conversion-in-c/)
- [cppreference.com - `std::strtof`, `std::strtod`, `std::strtold`](https://en.cppreference.com/cpp/string/byte/strtof)
- [cppreference.com - `HUGE_VALF`, `HUGE_VAL`, `HUGE_VALL`](https://en.cppreference.com/cpp/numeric/math/HUGE_VAL)
- [cplusplus.com - `strtol`](https://cplusplus.com/reference/cstdlib/strtol/)
- [cplusplus.com - `srand`](https://cplusplus.com/reference/cstdlib/srand/)
- [cplusplus.com - `rand`](https://cplusplus.com/reference/cstdlib/rand/)
- [cplusplus.com - `ctime`](https://cplusplus.com/reference/ctime/ctime/)