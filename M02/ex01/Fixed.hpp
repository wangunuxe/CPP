/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:11:33 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 13:11:36 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class	Fixed
{
private:
	int	_rawBits;
	static const int	_fractionalBits = 8;// the "static" requires that that the number of fractional bits must be shared by all obejcts, not stores per object. A non-static variable must be initialized in the constructor initilizer list.
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float fn);
	
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

};

std::ostream& operator<<(std::ostream& out, Fixed const& value);
#endif
