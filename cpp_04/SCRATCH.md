# CPP Module 04 notes
## ex00
### Learnings
- undertand polymorphism as an oop principle that allows to derived classes have different behaviours for the same function using virtual functions and dereferencing the pointer to access the most-derived class override of that function regardless of its static type.
- polymorphism can be dynamic (runtime) through the use of the virtual specifier and function overriding or static (compile time) using function and operator overloading.
- understand how dynamic polymorphism works using vptr and vtable, telling the compile to call whatever function that are in the specific function slot at runtime. This function turns to be the most-derive overide, not depending on the pointers static type, but the actual type of the object.
- the vtable is created for each class that has member function declared as virtual or overrides a virtual function of another class. One per class shared by all objects of that class. The vptr is set by the constructor to point to the corresponding vtable of that class.
- learned about object slicing, that happens in the implementation of dynamic polymorphism without the use of pointers or references, more specifically when the object is typed as a less derived class but is actual a more derived, slicing and not copying that data to the object.
- undestand when to declare the destructor virtual. If using dynamic polymorphism, the static type does not matter for the behaviour, and if the pointer have a different declaration, the destructor call will call consider the static type and be resolved in compile time, not runtime, which can cause to an object that was declared as `Base *objectName = new Derived()` to call the base destructor, skipping the derived destructor and causing an undefined behaviour.
### References
- [Jonathan Johnson - Polymorphism In Programming](https://www.bmc.com/blogs/polymorphism-programming/)
- [GeeksforGeeks - Virtual Function in C++](https://www.geeksforgeeks.org/cpp/virtual-function-cpp/)
- [cppreference.com - `virtual` function specifier](https://en.cppreference.com/cpp/language/virtual)
- [GeeksforGeeks - Object Slicing in C++](https://www.geeksforgeeks.org/cpp/object-slicing-in-c/)
- [GeeksforGeeks - vTable And vPtr in C++](https://www.geeksforgeeks.org/cpp/vtable-and-vptr-in-cpp/)
- [Lei Mao's Log Book - C++ Virtual Table](https://leimao.github.io/blog/CPP-Virtual-Table/)
- [W3 Schools - C++ Function Overloading](https://www.w3schools.com/cpp/cpp_function_overloading.asp)
- [cppreference.com - operator overloading](https://en.cppreference.com/cpp/language/operators)
- [GeeksforGeeks - Virtual Function in C++](https://www.geeksforgeeks.org/cpp/virtual-function-cpp/)
- [cppreference.com - `virtual` function specifier](https://en.cppreference.com/cpp/language/virtual)
- [GeeksforGeeks - When to Use Virtual Destructors in C++?](https://www.geeksforgeeks.org/cpp/when-to-use-virtual-destructors-in-cpp/)

## ex01
### Learnings
- First time creating resources and cleaning them in constructor and destructor respectively;
- Undestand the importance of deep copy. I was copying the pointer in the copy assignment operator of dog and cat classes, generating a shallow copy.

### References
## ex02
### Learnings
- Understand what are Abstract Classes.
- Abstract classes are classes that have one or more pure virtual functions
- pure virtual functions are declared, but not implemented and are resolved in runtime. This makes the class imponsible to be instanciated, being a template for a derived function that, if don't override it, will be also an abstract class.
- Derived classes that inherit an abstract class must override all pure virtual function in order to become a concrete class and be instantiated.
### References
- [Microsoft Learn - Abstract classes (C++)](https://learn.microsoft.com/en-us/cpp/cpp/abstract-classes-cpp?view=msvc-170)
- [Medium - Mastering C++ Abstract Class, Interface, and (Pure)Virtual Functions in Few Steps](https://medium.com/javarevisited/mastering-c-abstract-class-interface-and-pure-virtual-functions-in-few-steps-ddbeff770d1f)
- [GeeksforGeeks - Difference between Virtual function and Pure virtual function in C++](https://www.geeksforgeeks.org/cpp/difference-between-virtual-function-and-pure-virtual-function-in-c/)
## ex03
### Learnings
- undertand the definition of interface as a convetion name for pure abstract classes.
- the most challenging thing is to know what classes take ownership of the AMateria pointers and what do not.
- The subject is inconcistent about the ownership in learnMateria, saying that it copies the the Materia passed as parameter, but in the suggested main, the clone would generate a memory leak for passing new Ice() or new Cure() as param. Here is the complete description for possible readme:
## Ownership design (Ex03)

### `learnMateria(AMateria*)` — clones, does not take ownership

The subject's own wording is explicit: "Copies the Materia passed as a
parameter and stores it in memory so it can be cloned later." I implement
this literally: `learnMateria()` calls `clone()` on its argument and stores
the clone as the internal template. It never stores or deletes the pointer
it was given.

This means the caller retains full ownership of whatever they passed in —
before and after the call, successful or not. That also sidesteps the
full-array edge case entirely: whether or not `MateriaSource` has room for
another template, the original object was never the source's responsibility,
so there's nothing to leak or double-free either way.

The subject's suggested `main()` doesn't reflect this — it calls
`learnMateria(new Ice())` and never frees the argument, which leaks under a
literal reading of the spec. I corrected this in my own `main()`:

```c++
AMateria* ice = new Ice();
AMateria* cure = new Cure();
src->learnMateria(ice);
src->learnMateria(cure);
// ... use src normally ...
delete ice;
delete cure;
```

### `equip(AMateria*)` — takes ownership on success

Unlike `learnMateria()`, `equip()` is fed the result of `createMateria()`,
which returns a freshly cloned object with no other owner. Here `Character`
takes ownership of the pointer it's given (stores it as-is) and becomes
responsible for `delete`-ing it later, once a free slot was found. If the
inventory is full, per the subject ("nothing should happen"), `equip()` is a
no-op: it neither stores nor deletes the pointer, and ownership stays with
the caller.

### `unequip(int idx)` — never deletes, hands ownership back

Explicit in the subject: `unequip()` must never delete the Materia. It just
clears the slot; the caller becomes responsible for the pointer again (and
must have saved it themselves beforehand, since the interface returns void).

### Why the two functions differ

`equip()` and `learnMateria()` look similar but aren't interchangeable:
`equip()` is handed a *disposable, freshly-owned* object meant to live
inside the Character. `learnMateria()` is handed a *template* the caller
may still want to use, reuse, or manage independently — cloning it matches
that intent and matches the literal spec wording, rather than requiring an
inferred ownership-transfer contract that the subject never actually states.

### References
- [Abstract Classes vs. Interfaces: Decoding the OOP Dilemma in Software Engineering](https://www.quickstart.com/blog/software-engineering/when-and-how-to-use-abstract-class-and-interface/)
- 
