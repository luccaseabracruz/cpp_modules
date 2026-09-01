*This project has been created as part of the 42 curriculum by lseabra-.*

# C++ - Module 03

## Description
This module introduces **Inheritance**, one of the fundamental pillars of Object-Oriented Programming. While Modules 00-01 covered classes and dynamic references, and Module 02 focused on proper object design and operator overloading, Module 03 shows how to build hierarchies of related classes that share code and behavior.

In this module, you will learn:
- how to extend a base class with a derived class (single inheritance),
- how to properly chain constructors and destructors across inheritance levels,
- how to override and specialize member functions in derived classes,
- how derived classes inherit member attributes and can initialize them differently,
- the diamond problem that arises from multiple inheritance,
- virtual inheritance as a solution to the diamond problem.

The module is about understanding relationships:
- When should a class inherit from another, and when should it compose?
- How do I ensure the base class is always properly initialized before the derived class runs?
- How do I override a method while still respecting the contract of the base class?
- What happens when inheritance forms a diamond, and how do I resolve it?

### The module has 4 exercises:

| Exercise | Name | Topics | Description |
|---|---|---|---|
| ex00 | Aaaaand... OPEN! | classes, constructors, destructors, member functions | Build the ClapTrap base class with proper initialization and member functions. |
| ex01 | Serena, my love! | single inheritance, constructor chaining, method specialization | Create ScavTrap, which inherits from ClapTrap with different default values and abilities. |
| ex02 | Repetitive work | inheritance patterns, multiple derived classes | Create FlagTrap (FragTrap), another ClapTrap derivative with its own special ability. |
| ex03 | Now it's weird! | multiple inheritance, the diamond problem, virtual inheritance | Implement DiamondTrap, which inherits from both ScavTrap and FlagTrap, handling the diamond problem.

### The story arc of the module

The exercises are designed as a gradual progression in understanding inheritance:

1. **ex00**: Build the foundation
   - Create ClapTrap with proper construction, member functions, and state management.
   - This is the base that all subsequent classes will inherit from.
   - Understand the orthodox canonical form in the context of base classes.

2. **ex01-02**: Master single inheritance
   - Learn how to properly derive a class and initialize the parent.
   - Understand that derived classes inherit attributes and must specialize their values.
   - See how constructor chaining (base → derived) and destructor order (derived → base) work.
   - Realize that overriding methods allows derived classes to behave differently.
   - Repeat the pattern with FlagTrap to reinforce the concepts.

3. **ex03**: Confront the diamond problem
   - Inherit from two classes that both inherit from the same base (ClapTrap).
   - Discover that this creates ambiguity: is there one ClapTrap or two?
   - Use virtual inheritance to ensure only one instance of the shared base exists.
   - Understand how to use the scope resolution operator (`::`) to disambiguate member access.

This progression teaches that inheritance is about creating *is-a* relationships and reusing code, but it also introduces subtle design challenges that C++ forces you to handle explicitly.

### Exercise Breakdown

#### ex00: Aaaaand... OPEN!
**Goal**: Build the foundation class that all others will inherit from.

**What was learned**:
- How to design a base class with proper attributes and member functions.
- The role of constructors, destructors, and copy semantics in a class that will be inherited.
- How to protect internal state with access modifiers.

**Key implementation notes**:
- ClapTrap stores name, hitPoints, energyPoints, and attackDamage.
- Use `protected` instead of `private` so derived classes can access these attributes.
- Implement guard logic to prevent invalid state (e.g., hitPoints < 0, operations without energy).
- Each action (attack, takeDamage, beRepaired) must print a message describing what happened.

#### ex01: Serena, my love!
**Goal**: Understand how inheritance works and how to properly chain constructors.

**What you learn**:
- How to define a derived class and initialize its parent.
- How to override methods to specialize behavior.
- The order of construction and destruction across inheritance levels.
- How derived classes can have different default values for inherited attributes.

**Key implementation notes**:
- ScavTrap inherits from ClapTrap with different initial values: HP(100), EP(50), AD(20).
- The copy constructor must call the base copy constructor.
- ScavTrap overrides the `attack()` method to print a different message.
- ScavTrap has its own special ability: `guardGate()`.
- Tests must clearly show the construction/destruction order: base then derived during construction, reverse during destruction.

#### ex02: Repetitive work
**Goal**: Reinforce the inheritance pattern by creating another derived class.

**What you learn**:
- Repetition solidifies understanding of the inheritance pattern.
- Multiple derived classes from the same base can have different behaviors.
- How to design tests that verify construction order, copy semantics, and method behavior.

**Key implementation notes**:
- FlagTrap (FragTrap in the subject) is another ClapTrap derivative with different initial values: HP(100), EP(100), AD(30).
- FlagTrap has its own special ability: `highFivesGuys()`.
- The implementation pattern is nearly identical to ScavTrap, reinforcing that inheritance is reusable.
- Tests should include both copy constructor and copy assignment operator to verify the orthodox canonical form is maintained.

#### ex03: Now it's weird!
**Goal**: Navigate the complexity of multiple inheritance and the diamond problem.

**What you learn**:
- How multiple inheritance can lead to ambiguity.
- Virtual inheritance as a language feature to resolve the diamond problem.
- How to carefully initialize the shared base in the presence of multiple inheritance paths.
- How to use the scope resolution operator to access shadowed members.

**Key implementation notes**:
- DiamondTrap inherits from both ScavTrap and FlagTrap (which both inherit from ClapTrap).
- Both ScavTrap and FlagTrap must use `virtual public` inheritance from ClapTrap.
- DiamondTrap has:
  - A private `name_` attribute (different from ClapTrap's `name_`).
  - HP and AD from FlagTrap (100, 30).
  - EP from ScavTrap (50).
  - `attack()` from ScavTrap (via override-dominance rules).
- The copy constructor must handle both parent initializations and the virtual base.
- `whoAmI()` prints both the DiamondTrap name and the ClapTrap name (accessed via `ClapTrap::name_`).
- Tests must verify that ClapTrap is constructed only once and that all abilities work correctly.


## Instructions
### Requirements
- Compile with `c++` and the flags `-Wall -Wextra -Werror`.
- Code must still compile with `-std=c++98`.
- Class names in `UpperCamelCase`; a class file is named after the class (`ClassName.hpp`, `ClassName.cpp`).
- Header files must be self-contained (include their own dependencies) and protected with include guards.
- No implementation in header files, except for function templates (not used in this module).
- Forbidden: `*printf()`, `*alloc()`, `free()`, `using namespace ...`, `friend`.
- Forbidden until Module 08/09: STL containers (`vector`, `list`, `map`, ...) and `<algorithm>`.
- No external libraries (Boost, C++11 and later included).
- Any memory allocated with `new` must be freed (no leaks).
- From Module 02 onwards: classes must follow the Orthodox Canonical Form (default constructor, copy constructor, copy assignment operator, destructor), except where explicitly stated otherwise.

### How to Run
In every exercise directory, run the following in bash or similar shell:

```bash
make
```

To test, run the exercise executable generated by `make`. You can check the executable name in the `NAME` variable inside each Makefile.

In the Makefile, the common commands are:
- `make` or `make all`: compile the program.
- `make re`: clean object files and the executable, then compile everything again.
- `make clean`: remove object files.
- `make fclean`: remove object files and the executable.

## Resources

### Concepts Used

#### Inheritance Fundamentals
- **Single Inheritance** (ex02)
	- A derived class (`Child`) inherits from a base class (`Parent`).
	- The derived class automatically has access to all public and protected members of the base class and can override methods to specialize behavior.
	- Example: `ScavTrap` inherits from `ClapTrap` and overrides the `attack()` method.
- **Multiple Inheritance** (ex03)
	- A class can inherit from multiple parent classes: `class Child : public Parent1, public Parent2`.
	- If both Parent1 and Parent2 inherit from a common base `class Base`, then `Child` has two copies of `Base` (diamond problem).
	- Example: `DiamondTrap` inherits from `ScavTrap` and `FlagTrap`, which both inherit from `ClapTrap`. Without virtual inheritance, there would be two separate `ClapTrap` instances inside one `DiamondTrap`.
- **Virtual Inheritance** (ex03)
	- Mark an inheritance as `virtual` to ensure the shared base class exists only once. A mechanism to resolve the diamond problem in a multiple inheritance hierarchy.
	- Syntax: `class Derived : virtual public Base { ... }`
	- Example: In ex03, both ScavTrap and FlagTrap inherit from ClapTrap using `virtual public`. DiamondTrap then has only one ClapTrap instance, eliminating ambiguity.

#### Constructor and Destructor Chaining
- When a derived class is constructed, the base class constructor is called first.
- In C++, this is done via the member initialization list: `Child::Child() : Parent(args) { ... }`
- Syntax: `Derived::Derived(args) : Base(base_args), member_(value) { ... }`
- In C++98, the initialization list is the *only* way to initialize a base class.
- Destruction happens in reverse order: the derived destructor runs first, then the base destructor.

#### Method Overriding
- A derived class can define a method with the same signature as a base class method.
- The derived version shadows (hides) the base version, allowing specialization of behavior without changing the base class.
- To call the base version explicitly, use the scope resolution operator: `Parent::method()`.

#### Protected Members
- In a base class, `protected` members are accessible to derived classes but not to outside code, allowing derived classes to access and modify inherited attributes without exposing them publicly.
- Example: ClapTrap uses `protected` for its attributes so that ScavTrap and FlagTrap can access them.

#### The Scope Resolution Operator (`::`)
- Used to explicitly access a member from a specific class when they have members with the same name, resolving ambiguity.
- Example: `ClapTrap::name_` accesses the `name_` from ClapTrap, not from DiamondTrap.

#### Design Patterns
- **Inheritance for specialization**: Different classes inherit from a common base class.
- **Inheritance for code reuse**: ScavTrap and FlagTrap reuse all of ClapTrap's logic.
- **Template Method Pattern** (implicit): Derived classes override specific methods while inheriting the rest.

### Common Pitfalls

#### Forgetting Virtual Inheritance
- If ScavTrap and FlagTrap inherit from ClapTrap without `virtual`, DiamondTrap will have two copies of ClapTrap.
- This leads to ambiguity: which `hitPoints_` are you referring to?
- Always use `virtual public` when designing classes that may be used in multiple inheritance.

#### Not Initializing the Virtual Base
- In a virtual inheritance hierarchy, the most-derived class (DiamondTrap) must explicitly initialize the virtual base (ClapTrap) in its constructor's initializer list.
- If DiamondTrap doesn't call `ClapTrap(...)` in its initializer list, the virtual base constructor may not run correctly.

#### Shadowing Attributes
- DiamondTrap has its own `name_` attribute, separate from `ClapTrap::name_`.
- Accessing `name_` without a scope qualifier will use DiamondTrap's version (higher precedence of the most derived overide).
- To access ClapTrap's `name_`, use `ClapTrap::name_`.

#### Not Overriding the Copy Assignment Operator
- If you have a class with derived classes, the base class copy assignment operator is not automatically correct for derived classes.
- Each class (including derived ones) should implement its own copy assignment operator that handles all members correctly.

### References

- [cppreference.com - Inheritance](https://en.cppreference.com/w/cpp/language/derived_class)
- [cppreference.com - Virtual base classes](https://en.cppreference.com/w/cpp/language/derived_class#Virtual_base_classes)
- [cppreference.com - Member initialization list](https://en.cppreference.com/w/cpp/language/initializer_list)
- [cppreference.com - Access specifiers](https://en.cppreference.com/w/cpp/language/access)
- [Medium - Object-Oriented Programming : Inheritance](https://medium.com/@hasan_denli/object-oriented-programming-inheritance-44daf3801d45)
- [GeeksforGeeks - Inheritance in C++](https://www.geeksforgeeks.org/cpp/inheritance-in-c/)
- [GeeksforGeeks - Diamond Problem in C++](https://www.geeksforgeeks.org/cpp/diamond-problem-in-cpp/)
- [Medium - Untangling the Diamond Problem in C++](https://levelup.gitconnected.com/untangling-the-diamond-problem-in-c-6fa5caeb5ea4)

### AI Usage
AI was used during this project as a tutor and support tool, specifically for:
- Explaining the diamond problem and virtual inheritance in C++98 context;
- Validating inheritance design decisions and constructor chaining logic;
- Proofreading and improving this README.

No AI was used to provide direct solutions to the exercises.

## Final Reflection

Module 03 is where the power of OOP becomes visible. Inheritance allows you to build hierarchies of related types, reuse code across multiple classes, and express relationships between types. However, it also introduces complexity: the diamond problem is a real challenge in C++, and virtual inheritance is a non-trivial solution that requires careful thinking.

The progression from ex00 (simple base class) through ex01-02 (single inheritance patterns) to ex03 (virtual inheritance and disambiguation) mirrors the journey many C++ developers take when learning these concepts. By the end, the module fosters a deep understanding of how inheritance works, what can go wrong, and how C++ tools (virtual inheritance, scope resolution) help you write correct code.

The key takeaway: inheritance is powerful for expressing relationships and reusing code, but it demands careful design and explicit handling of edge cases like the diamond problem.