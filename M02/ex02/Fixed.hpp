#ifndef FIXED_HPP
# define FIXED_HPP
# include <cmath>
class Fixed
{
private:
	int	_rawBits;
	static const int	_fractionalBis = 8;
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int	getRawBits(void) const;
	void	setRawBits(int const raw);

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
	Fixed& operator++();//"a++"Save old value first; next, Modify; 
};
#endif