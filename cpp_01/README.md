*This project has been created as part of the 42 curriculum by lseabra-.*
 
# C++ - Module 00
 
## Description
First module of C++ in the Common Core curriculum. It introduces Object-Oriented Programming by 
moving from C to C++98, introducing important concepts of the language like  classes, member functions, 
`stdio` streams, initialization lists, `static`, `const`, and the general C++ project conventions used 
in the following modules.
 
The module has 3 exercises:
| Exercise | Name | Topics | Description |
|---|---|---|---|
| ex00 | Megaphone | argv parsing in C++, `std::string`, `std::cout`, manual uppercase conversion | A program that receives an input through argv and displays it in uppercase |
| ex01 | My Awesome PhoneBook | classes, encapsulation, fixed-size arrays (no dynamic allocation), `std::cin`, `<iomanip>` | A program that simulates a phone book that registers contacts and searches for them |
| ex02 | The Job of Your Dreams (BONUS) | class implementation from a header + log file, constructors/destructors, `static` members, `const` members, encapsulation | Receive a header file and a .log file for a reverse-engineering mission: implement the constructor, destructor and member functions, and understand static members and vectors along the way |
 
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
In every exercise, run the following in bash or similar shell:
```bash
make
```
To test, run the exercise executable generated on make. You can check the name of the executable in the NAME variable inside each Makefile.
 
In the Makefile, you have the commands:
- ```make``` or ```make all```: compile the program.
- ```make re```: does a full clean on object files and executable and compile the program again.
- ```make clean```: clean object files.
- ```make fclean```: similar to clean, but also deletes the executable.
## Resources
### Concepts Used
#### C++ definition and history
- C++ as an increment of C, using the ++ operator to represent it.
- Created by Bjarne Stroustrup, who started working on it in 1979 as "C with Classes" — it only got renamed to C++ in 1983.
- A general purpose language that supports OOP and Procedural Programming paradigms.
- High level execution, low-level memory control, rich Standard Library and widely used.
#### Object Oriented Programming (OOP)
- Principles of OOP: encapsulation, inheritance, polymorphism and abstraction.
- The most important principles in this module were encapsulation and abstraction, grouping all variables and functions related inside the same class, implementing access control, hiding the implementation complexity and exposing just the necessary.
- Classes as an abstraction of a real-world concept/entity, a data-type that centralizes this entity's data and methods.
- Object as an instance of a class that it's possible to interact with.
#### Constructors, destructors, initialization lists
- Use of constructor/destructor special members, managing the object lifecycle in ex01 and ex02.
- Member initialization lists vs assignment in the constructor body.
#### `std` I/O streams
- `<iostream>`: `std::cin` / `std::cout` instead of `scanf`/`printf` (C functions are forbidden here).
- `<iomanip>`: `std::setw`, alignment to reproduce the fixed-width, right-aligned, dot-truncated table required in ex01.
- `std::string` instead of `char *`/`char[]` — no manual buffer management, safer concatenation/comparison.
#### `static` and `const`
- `static` member variables (shared across all instances)
- `static` member functions that can just access other static members and don't have `this` implicit pointer because it doesn't belong to an object, but to the class itself.
- `const` correctness: `const` member functions, `const` parameters/references — the compiler now enforces "this doesn't mutate state" instead of it being a comment in C.
#### char * vs std::string
- `char *` is a low-level pointer to a sequence of chars, with no built-in size or safety. If it points to a string literal it's not safe to modify (undefined behavior); if it points to a writable buffer (a stack array, `new[]`, etc.) it's mutable like any other memory. Either way you're the one tracking the size and the null terminator, which is why it has less overhead than `std::string`.
- `std::string` (Class of C++ Standard Library) is a class that abstracts the string management process. It automatically manages the storage of the container and provides methods to operate on it. It's safer to use, but less efficient in terms of memory.
#### Reading an existing class implementation
- ex02: given `Account.hpp` and a log file, reverse-engineer `Account.cpp` — practice reading a class's public interface and inferring intended behavior/side effects before writing any code.
#### Understanding vectors in C++
- To do the ex02, it's important to understand the concept of vectors used in the `tests.cpp` file to generate the log file.
- vectors are a STL container class template that encapsulates a dynamic array where data is contiguously stored and automatically managed by the class.
#### Common C → C++ mistakes avoided here
- Treating a `class` like a C `struct` and making everything `public`.
- Assigning members in the constructor body instead of using the initialization list.
- Forgetting `const` on member functions that don't modify state.
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
- [C++ Vectors - W3 schools](https://www.w3schools.com/cpp/cpp_ref_vector.asp)
### AI usage
AI (ChatGPT / Claude / Gemini) was used during this project as a support tool, specifically for:
- Clarifying important concepts such as static member functions, good practices in C++, and differences between C and C++.
- Proofreading and improving the content written and structured of this README.
- No AI was used to give solutions, just validating ideas in terms of design trade-offs and best practices.