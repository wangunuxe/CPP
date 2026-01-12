#include "Fixed.hpp"

const int	_fractionalBits = 8;

Fixed::Fixed() : _rawBits(0){};

Fixed:: ~Fixed(){};

int Fixed::getRawBits(void) const
{
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}
//The new object is created from one existing object "other" -> make the new object a cope of  "other"
Fixed::Fixed(const Fixed& other)
{
	*this = other;
}
//One existing object "other" is assigned another existing object
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return *this;
}

//compare numeric values of two "Fixed" object: Because all Fixed objects use the same scale (2⁸), we can compare _rawBits directly
bool	Fixed::operator>(const Fixed& other) const
{
	return	this->_rawBits > other.getRawBits();
}
bool	Fixed::operator<(const Fixed& other) const
{
	return this->_rawBits < other.getRawBits();
}
bool	Fixed::operator>=(const Fixed& other) const
{
	return this->_rawBits >= other.getRawBits();
}
bool	Fixed::operator<=(const Fixed& other) const
{
	return this->_rawBits <= other.getRawBits();
}
bool	Fixed::operator==(const Fixed& other) const
{
	return this->_rawBits == other.getRawBits();
}
bool	Fixed::operator!=(const Fixed& other) const
{
	return this->_rawBits != other.getRawBits();
}

//Arithmetic operators: Each operator returns a NEW Fixed oject
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed	res;
	res.setRawBits(this->_rawBits + other.getRawBits());
	return res;
}
Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed	res;
	res.setRawBits(this->_rawBits - other.getRawBits());
	return res;
}
Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed	res;
	long tmp = (long)this->_rawBits * (long)other.getRawBits();// a * 2^8 * b * 2^8
	res.setRawBits(tmp >> _fractionalBis);
	return res;
}
Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed	res;
	res.setRawBits ((this->_rawBits << _fractionalBis) / other.getRawBits());
	return res;
}

