# The Rule of Three in C++

The Rule of Three is a C++ (pre-C++11) design guideline: if a class needs a
user-defined **destructor**, **copy constructor**, or **copy assignment
operator**, it almost certainly needs all three.

These three special member functions manage an object's resource lifecycle.
The default constructor is *not* part of the rule — it initializes a new
object from scratch rather than governing copies or destruction.

## Why it matters

The problem is **resource ownership**. If object `b` owns a pointer to
dynamically allocated memory `x`, and the compiler-generated copy
constructor/assignment operator is used, they perform a **shallow copy**:
both `a` and `b` end up pointing to the same `x`.

- If `a`'s destructor deletes `x`, `b` is left with a **dangling pointer**.
- When `b` is later destroyed, it deletes `x` again → **double free**,
  undefined behavior.

C++11 added move semantics and extended this to the **Rule of Five**
(move constructor + move assignment operator). In C++98 you only have
the Rule of Three.

---

## 1. Copy Constructor

Creates a new object as a copy of an existing one. Triggered by
**copy initialization**, not by `operator=`.

```cpp
#include <iostream>
#include <string>

class Friend
{
	private:
		std::string name_;
	public:
		Friend(void) : name_("") {}
		Friend(std::string name) : name_(name) {}
		Friend(const Friend& other)
		{
			std::cout << "Copy constructor called\n";
			name_ = other.getName();
		}
		std::string getName(void) const
		{
			return name_;
		}
};

int main(void)
{
	Friend a("Eric");
	Friend b(a);   // copy constructor call

	std::cout << a.getName() << '\n';
	std::cout << b.getName() << '\n';
}
```

```
$ ./a.out
Copy constructor called
Eric
Eric
```

Take the parameter by `const Friend&`, not `Friend&` — you don't need to
modify `other`, and a const reference also allows copying from temporaries
and const objects. The compiler provides a default copy constructor if none
is defined; it does a shallow copy.

---

## 2. Copy Assignment Operator

`operator=` — handles copying into an **already-existing** object.
Unlike the copy constructor, it runs *after* both objects exist.

```cpp
#include <iostream>
#include <string>

class Person
{
	private:
		std::string name_;
	public:
		Person(void) : name_("")
		{
			std::cout << "Default constructor called\n";
		}
		Person(const std::string& name) : name_(name)
		{
			std::cout << "Constructor called\n";
		}
		Person& operator=(const Person& other)
		{
			std::cout << "Copy assignment operator called\n";
			name_ = other.getName();
			return (*this);
		}
		std::string getName(void) const
		{
			return name_;
		}
};

int main(void)
{
	Person john("John");
	Person marshall("Marshall");

	marshall = john;   // copy assignment operator
	std::cout << john.getName() << std::endl;
	std::cout << marshall.getName() << std::endl;
}
```

```
$ ./a.out
Constructor called
Constructor called
Copy assignment operator called
John
John
```

**Important distinction:** `Person marshall = john;` is **copy
initialization**, not assignment — it calls the copy constructor, same as
`Person marshall(john);`, because `marshall` doesn't exist yet.

```
$ ./a.out
Constructor called
John
John
```

Common mistake: forgetting to `return *this`, and forgetting to guard
against self-assignment (`if (this == &other) return *this;`) when the
class manages a resource that gets freed before being reassigned.

---

## 3. Destructor

Prefixed with `~`, called automatically when an object's lifetime ends
(scope exit or `delete`). Releases resources the object owns — dynamically
allocated memory, file handles, etc. A destructor cannot be overloaded;
there is exactly one per class.

```cpp
#include <iostream>

class Test
{
	public:
		int* num;

		Test()
		{
			std::cout << "Constructor Called" << std::endl;
			num = new int(0);
		}
		~Test()
		{
			std::cout << "Destructor Called" << std::endl;
			delete num;
		}
};

int main()
{
	Test t;
	return 0;
}
```

```
$ valgrind ./a.out
Constructor Called
Destructor Called
==13904== HEAP SUMMARY:
==13904==     in use at exit: 0 bytes in 0 blocks
==13904==   total heap usage: 3 allocs, 3 frees, 74,756 bytes allocated
==13904== All heap blocks were freed -- no leaks are possible
```

---

## Summary

| Function | Called when | Default behavior | Danger with owned resources |
|---|---|---|---|
| Copy constructor | New object initialized from existing one | Shallow copy | Two objects point to same memory |
| Copy assignment | Existing object assigned from another | Shallow copy | Leak old resource + double free |
| Destructor | Object goes out of scope / `delete` | Does nothing extra | Resource never released if missing |

**Rule:** if you write one, write all three (and give the class a proper
deep copy / ownership model, or disable copying entirely by making them
private and unimplemented in C++98).

## References
- [Rule of three/five/zero — cppreference](https://en.cppreference.com/cpp/language/rule_of_three)
- [Copy constructor — cppreference](https://en.cppreference.com/cpp/language/copy_constructor)
- [Copy assignment operator — cppreference](https://en.cppreference.com/cpp/language/copy_assignment)
- [Destructors — cppreference](https://en.cppreference.com/cpp/language/destructor)