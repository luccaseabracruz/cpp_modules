# Learnings
## ex00
Create a class  to represent a fixed point with ortodox cannonical form
- The 42 orthodox cannonical form is basically the rule of 3 in c++ including the default constructor.
- definition of a Fixed-point value:
	- an int type that reserves a number of bits for the fractional part.
	- to convert to int, shift the bits n times, with n beeing the number of fractional bits.
		- equivalent to $rawBits * 2^n$, that in this case is $2^8 = 256$.
	- to convert to float, remember that the fixed-point rawBits is equivalent to $realValue * 2^fractBitsN$, so:
		floatValue = (cast to float)rawBits / (1 << fractBitsN)

## ex01
- convert int to fixed-point value;
- convert float to fixed-point value;
- convert fixed-point value to int;
- convert fixed-point value to float;
- creating a free operator<< function that receives the object and specifies how it should be written in the ofstream.
- rule where to place the overload. If returns a user-defined class, should be inside its scope. If not user-defined and cannot change the class, shoud be outside the class as a free function. What matters is what comes before the function name, is the place the function should be (if you can).

## ex02
- arithmetic operators overload
	- most dificult was to undestand that the division and multiplication were different because of the binary arithmetic of the fixed point number
		- $(x / 2^n) + (x / 2^n) = (x + x) / 2^n$ and $(x / 2^n) * (x / 2^n) = (x * x) / 2^{n + n} = 2x / 2^{2n}$
		- roundf rounds to the nearest representable integer before the cast, which is the standard quantization technique for minimizing representation error when converting a continuous value into a fixed-point grid.
- comparison operators overload
- increment/decrement operators overload
	- the pre increment increment receives int just to differentiate from post increment;
	- post increment cost more for storing the old state (copy of the real)to be returned while incrementing the real state.
		- use pre-inc when it does not matter.
- min and max functions. If `a` == `b`, always return `a`.

## ex03
