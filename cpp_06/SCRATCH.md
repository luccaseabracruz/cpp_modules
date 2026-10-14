# CPP Module 04 notes
## ex00
### Learnings
- can't use std::stod because it's from C++11 and later versions.
- use std::strtod to convert string to double. It's from `<cstdlib>`, jump spaces and has receives a pointer to a pointer to save position where it stoped to interpret (where the non-digit was found).
- casting double infinite to float infinite is safe.
- using std::stol to convert str to long and then to int.
- undestand how to use std::numeric_limits.
- numeric_limits::min() returns the lowest positive in case of floating-point numbers (not what I expected). C++11 has numeric_limits::lower(), but C++98 use -std::numeric_limits::max() as pattern.
### References
- [cppreference.com - std::strtof, std::strtod, std::strtold](https://en.cppreference.com/cpp/string/byte/strtof)
- [cppreference.com - HUGE_VALF, HUGE_VAL, HUGE_VALL](https://en.cppreference.com/cpp/numeric/math/HUGE_VAL)
- [cplusplus.com - strtol](https://cplusplus.com/reference/cstdlib/strtol/)

## ex01
### Learnings
- understand deeper the static_cast, a way to convert at check at compile-time. It's prefered for numeric versions, but also converts reverse implicit conversions (void* to int* for example), and downcasting in inheritance hierarchies (static_cast<BaseClass>(DerivedClass)).
- understand what reinterpret_cast does and how to use it. It's a low-level type casting operator that converts objects, references and pointers to unrelated types, reinterpreting the bit pattern into the other type. It has little type safety.

### References

## ex02
### Learnings
- understand how dynamic_cast work for identify the class type in runtime. Its an operator to upcast or downcast an object. When the object isn't from the class that is trying to cast, it returns Null in case of pointer and throws an error in case of reference.
### References
