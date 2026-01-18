/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:11:45 by jili              #+#    #+#             */
/*   Updated: 2026/01/18 12:42:52 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

//constructors, copy assignment and destructor
Fixed :: Fixed() : _rawBits(0)
{
	std::cout << "Default constrictor called" << std::endl;
}

Fixed :: Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = n << _fractionalBits;// shift n left by 8 bits;Fixed-point value = integer × 2⁸
}

Fixed :: Fixed(const float fn)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(fn * (1 << _fractionalBits));//"roundf" rounds a floating-point number to the nearest integer value
}

Fixed :: Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//getter and setter
int	Fixed :: getRawBits(void) const
{
	return this->_rawBits;
}

void	Fixed :: setRawBits(int const rawBits)
{
	this->_rawBits = rawBits;
}

//member functions
float Fixed :: toFloat(void) const
{
	return (float)_rawBits / (1 << _fractionalBits);// If cast to float, it keeps decimals; 
	//If _rawBits is an int, the result is : Truncation toward zero = remove the decimal part, without rounding, moving the value closer to 0.
	//for (1 << _fractionalBits):the int is automatically promoted to float
}

int	Fixed :: toInt(void) const
{
	return _rawBits >> _fractionalBits; // shift _rawBits right by 8 bits
}

//overloading operator
std::ostream& operator<<(std::ostream& out, Fixed const& value)
{
	out << value.toFloat();
	return out;
}