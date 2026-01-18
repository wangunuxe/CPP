/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:12:11 by jili              #+#    #+#             */
/*   Updated: 2026/01/18 13:26:35 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() : _rawBits(0){};
//constructors, copy assignment, destructor
Fixed::Fixed(const int n)
{
	this->_rawBits = n << _fractionalBits;
}

Fixed::Fixed(const float fn)
{
	this->_rawBits = roundf(fn * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return *this;
}
Fixed:: ~Fixed(){};

//getter and setter
int Fixed::getRawBits(void) const
{
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

//convert to float and int
float Fixed::toFloat() const
{
	return (float)_rawBits/ (1 << _fractionalBits);
}

int	Fixed :: toInt(void) const
{
	return _rawBits >> _fractionalBits; // shift _rawBits right by 8 bits
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
	res.setRawBits(tmp >> _fractionalBits);
	return res;
}
Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed	res;
	res.setRawBits ((this->_rawBits << _fractionalBits) / other.getRawBits());
	return res;
}

//increment and decrement
//Pre-increment returns a reference to the same object,
Fixed& Fixed::operator++()//"++a" Modify first, return reference : T& operator++()
{
	this->_rawBits++;
	return *this;
}
//Post-increment returns a copy (a new object): T operator++(int)
Fixed Fixed::operator++(int)//"a++" Save old value first; next, Modify;
{
	Fixed tmp(*this);
	this->_rawBits++;
	return tmp;
}

Fixed& Fixed::operator--()
{
	this->_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_rawBits--;
	return tmp;
}

//min and max non-const version / const version
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}
Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

//overloading operator <<
std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return out;
}
