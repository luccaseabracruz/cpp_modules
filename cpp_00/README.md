*This project has been created as part of the 42 curriculum by lseabra-.*

# C++ - Module 00

## Description
First module of C++ in the Common Core curriculum. It introduces Object-Oriented Programming by 
moving from C to C++98, introducing important concepts of the language like  classes, member functions, 
`stdio` streams, initialization lists, `static`, `const`, and the general C++ project conventions used 
in the following modules.

The module has 3 exercise:
| Exercise | Name | Topics | Description |
|---|---|---|---|
| ex00 | Megaphone | argv parsing in C++, `std::string`, `std::cout`, `<algorithm>`/manual uppercase  with| A program that receives a input though argv and display it in uppercase |
| ex01 | My Awesome PhoneBook | classes, encapsulation, fixed-size arrays (no dynamic allocation), `std::cin`, `<iomanip>` | A Program that simulates a phone book that register contacts and search for them.|
| ex02 | The Job of Your Dreams | class implementation from a header + log file, constructors/destructors, `static` members, `const` members (BONUS) | receive a .hpp file with a mission of implement its constructor, destructor and member functions, dealing with static members and vectors. |
 

## Instructions
### Requirements
- Compile with `c++` and the flags `-Wall -Wextra -Werror`.
- Code must still compile with `-std=c++98`.
- Class names in `UpperCamelCase`; a class file is named after the class
  (`ClassName.hpp`, `ClassName.cpp`).
- Header files must be self-contained (include their own dependencies) and protected
  with include guards.
- No implementation in header files, except for function templates (not used in this module).
- Forbidden: `*printf()`, `*alloc()`, `free()`, `using namespace ...`, `friend`.
- Forbidden until Module 08/09: STL containers (`vector`, `list`, `map`, ...) and
  `<algorithm>`.
- No external libraries (Boost, C++11 and later included).
- Any memory allocated with `new` must be freed (no leaks).
### How to Run
In every exercice, you have to run on bash or similar interpreter:
```bash
make
```
To test, run the exercise executable generated on make.

In the Makefile, you have the commands:
- ```make``` or ```make all```: compile the program.
- ```make re```: does a full clean on object files and executable and compile the program again.
- ```make clean```: clean object files.
- ```make fclean```: similar to clean, but also deletes the executable.

## Resources

### Concepts Studied
#### Namespaces
- `std::` namespace and why `using namespace std;` is banned in this module (forbidden
  keyword, and it also just pollutes the global namespace — same reason you'd avoid
  wildcard imports in any language).
#### Classes and encapsulation
- Difference between a `struct` (C mindset: bag of public data) and a `class` used with
  private state, public interface (`PhoneBook` / `Contact` in ex01).
- Member functions vs free functions: behavior now lives with the data it operates on.
- Access specifiers (`private`/`public`) as the C++ way to enforce invariants that in C
  you'd only get by convention (e.g. "never touch this field directly").
#### Constructors, destructors, initialization lists
- Constructor/destructor pairing replaces manual `init()`/`destroy()` function pairs from C.
- Member initialization lists vs assignment in the constructor body — and why lists are
  preferred (avoids a default-construct-then-assign for members, required for `const`
  and reference members).
- Destructor call order (reverse of construction) — noted explicitly in ex02, since it's
  compiler/OS dependent and a common source of confusion.
#### `stdio` streams
- `std::cin` / `std::cout` instead of `scanf`/`printf` (which are forbidden here).
- `<iomanip>`: `std::setw`, alignment, and truncation to reproduce the fixed-width,
  right-aligned, dot-truncated table required in ex01.
- `std::string` instead of `char *`/`char[]` — no manual buffer management, safer
  concatenation/comparison.
#### `static` and `const`
- `static` member variables (shared across all instances) vs `static` member functions
  (no implicit `this`, can't access non-static members).
- `const` correctness: `const` member functions, `const` parameters/references — the
  compiler now enforces "this doesn't mutate state" instead of it being a comment in C.
#### Fixed-size / no dynamic allocation
- ex01 forbids dynamic allocation: managing a bounded, circular-overwrite structure
  (8 contacts, oldest replaced) with a plain array instead of `malloc`/`realloc` tricks.
#### Reading an existing class implementation
- ex02: given `Account.hpp` and a log file, reverse-engineer `Account.cpp` — practice
  reading a class's public interface and inferring intended behavior/side effects
  before writing any code, rather than guessing at the API.
#### Common C → C++ mistakes avoided here
- Reaching for `malloc`/`free` or `printf`/`scanf` out of habit (both forbidden).
- Treating a `class` like a C `struct` and making everything `public`.
- Assigning members in the constructor body instead of using the initialization list.
- Forgetting `const` on member functions that don't modify state.
#### C++ definition and history
#### Object Oriented Programming (OOP)
#### std::string abstracts string management
#### Static Member and Function Member in C++
#### STL (Standard Template Library)
#### Vectors in C++

- 

### References

- [cppreference.com](https://www.cppreference.com/)
- [Introduction to C++ - GeeksforGeeks](https://www.geeksforgeeks.org/cpp/cpp-programming-intro/)
- [History of C++ - GeeksforGeeks](https://www.geeksforgeeks.org/cpp/history-of-c/)
- [Object - cppreference.com](https://en.cppreference.com/cpp/language/object)
- [C++ OOP - W3 schools](https://www.w3schools.com/cpp/cpp_oop.asp)
- [Introduction of Object Oriented Programming - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/introduction-of-object-oriented-programming/)
- [Static Member Function in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/cpp/static-member-function-in-cpp/)
- [char* vs std:string vs char[] in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/cpp/char-vs-stdstring-vs-char-c/)
- [STL Demystified: A Practical Guide to C++ Standard Template Library](https://medium.com/@athicharttangpong/stl-demystified-a-practical-guide-to-c-standard-template-library-1f097ea90778)
- [std::vector - cppreference.com](https://en.cppreference.com/cpp/container/vector)
- [Vector in C++ STL - GeeksforGeeks](https://www.geeksforgeeks.org/cpp/vector-in-cpp-stl/)
- [C++ Vector Library - W3 schools](https://www.w3schools.com/cpp/cpp_ref_vector.asp)
- [C++ Vectors - W3 schools](https://www.w3schools.com/cpp/cpp_ref_vector.asp)

### AI usage

AI (ChatGPT / Claude / Gemini) was used during this project as a support tool, specifically for:

- Clarifying important concepts such as static member functions, good practices in C++, and differences between C and C++.
- Proofreading and improving the content written and structured by me of this README.
- No AI was used to give solutions, just validating ideias in terms of design trade-offs and best practices.