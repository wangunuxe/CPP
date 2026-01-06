#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}


// ex00 is about:
// 1. Orthodox Canonical Form
// 2. Understanding constructors / destructor
// 3. Copy behavior
// 4. static const
// 5. Basic encapsulation (getter / setter)

// *** Fixed-point number in mathematics:
//     Fixed-point number is a number with a decimal point. The position of the decimal point is fixed by the definition and by design.
//     ** In programming, a fixed-point number is stored using an integer type.(The integer is the representation, not the number itself.)
//         *stored_integer = real_value × scaling_factor
//         *scaling_factor = 2^fractionalBits
//     * The fixed scaling factor: A number by which we multiply or divide to change how a value is interpreted. In the project, We store values multiplied by 256, BUT We read values divided by 256>
//     * 
//     |----|----|----|----|----|----|----|----|
//     1/2 1/4  1/8 1/16 1/32 1/64 1/128 1/256

