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
- create a a program that reads an existent file and create/write an output file, but replacing s1 for s2.
- introduces stream management functions.
- can't use string std::replace, using find find, remove and insert functions.
# Open Questions
- [X] Makefile: is it necessary to use CPP_VERSION to compile .o files?
	R: Yes, it is necessary

- [ ] I don't know how the principles are applied here
### ex04
- [ ] difference between size_type and size_t and unsigned it;
	- are size_t and size_type ways to guard the size depending of the capacity of the processor or size definition of size of the current os?
- What is string::npos?
- learned about the return and studied modular arythmetic to explain the npos and why is important to use size_t or string::size_type to work well with all systems and compilors.

### ex05
- I had to create a Class Harl, a guy that complains and call the right function depending on the level of complaint passed as std::string as a param and trigger the function without using a forest of ifs, using a list of pointers to the member functions.
- introduces pointers to member functions;

### ex06
- same as the ex05, but using switch operator and triggering all levels since the level passed as parameter.
- understand how switch work, as a cascade without implicit break and just work with its.
- introduces switch case;