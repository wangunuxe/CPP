#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
private:
	int	_rawBits;
	static const int	_fractionalBits = 8;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float fn);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat() const;

	//compare numeric values of two "Fixed" object
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	//Arithmetic operators: Each operator returns a NEW Fixed oject
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	//increment and decrement : increase or decrease by the smallest representable ε = 1 / 256; (the smallest positive value your Fixed class can represent : real_value = _rawBits / 2^fractionalBits)
	Fixed& operator++();//"++a" Modify first, return reference
	Fixed operator++(int);//"a++" Save old value first; next, Modify; 
	Fixed& operator--();
	Fixed	operator--(int);

	//min and max non-const version / const version
	static Fixed&	min(Fixed& a, Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& out, const Fixed& value);//must add "const", because the printing must NOT modify the object
#endif