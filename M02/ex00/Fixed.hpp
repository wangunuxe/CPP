#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits;

public:
	// Orthodox Canonical Form
	Fixed();
	Fixed(const Fixed& other);//copy constructor
	Fixed& operator=(const Fixed& other);//copy assignment operator
	~Fixed();
	// Getter / Setter
	int  getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif

// ***Fixed& operator=(const Fixed& other);***
// 	**declare the copy assignment operator; This function is called when the = operator is used on this class.
// 	**"operator=" the name of the function;
// 	** "const Fixed& other": the paramater is the right-hand side of the assignment. "a = b"
// 	**"Fixed&" : the return of the function

// *** The difference between COPY CONSTRUCTOR and COPY ASSIGNMENT:
// 	** COPY CONSTRUCTOR is for "Cloning"
// 		Fixed a;
// 		Fixed b(a);
// 		or
// 		Fixed b = a;
// 		*Fixed b does not exist yet, we use Fixed a to create b;
// 		*Constructor : allocate + initialize
// 	** COPY ASSIGNMENT is for "overwriting"
// 		Fixed a;
// 		Fixed b;
// 		b = a;
// 		*Fixed b already exists, we use Fixed a to overwrite b;
// 		*assignment: reuse the existing memory

// *** The "const" at the end of "int  getRawBits(void) const" means :
// 	This function will not modify the object(*this)