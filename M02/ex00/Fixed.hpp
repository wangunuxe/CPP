/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:10:56 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 16:33:16 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

