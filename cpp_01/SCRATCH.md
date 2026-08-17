# Learnings
## ex00
- create two functions, one creates a zombie and the other creates it and announce himself inside the function scope. The key is deciding where to allocate (stack or heap).
- Dynamic allocation with keyword new
- When to allocate on stack or heap
## ex01
- based on ex00, create a function that receives a name and an int that represents the size of the Zombie array that needs to be created.
- this exercise introduces dynamic arrays in C++.
## ex02
- demands to print the var, the reference pointer to the var and the reference to the var to undertand the concept of reference.
- introduces the concept of reference and the differences between variable, pointer and reference.
- reference is a practical way to deal with pointers. A reference to `int x` is another alias for the same variable, allowing you to modify the original one.
- passing a variable by reference is usefull to avoid copying the whole class to the param. If you don't want to modify, just pass `const std::string& str` and use the original as reference to do something inside the function. 

## ex03
- Write Three classes and:
	- `Weapon`: has a `std::string type` member;
	- `HumanA`: receives a Weapon and name on through constructor (always armed);
	- `HumanA`: same as HumanA, but does not receive a Weapon on through constructor (can be unnarmed);
- Decide where where is better to use pointer or reference in each human class.

## ex04
# Open Questions
- [X] Makefile: is it necessary to use CPP_VERSION to compile .o files?
	R: Yes, it is necessary

- [ ] I don't know how the principles are applied here