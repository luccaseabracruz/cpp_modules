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
### To do
### Learnings
### References
## ex02
### To do
### Learnings
### References
## ex03
### To do
### Learnings
### References
