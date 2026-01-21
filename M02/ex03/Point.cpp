/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:29:20 by jili              #+#    #+#             */
/*   Updated: 2026/01/21 11:29:22 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0){}

Point::Point(const float a, const float b) : x(a), y(b){}
// const data member MUST be initialized in the constructor initializer list
Point::Point(const Point& other): x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{
	// the code is illegal, because x and y are const, C++ forbids assignment to const members.
	// if (this != &other)
	// {
	// 	this->x = other.x;
	// 	this->y = other.y;
	// }
	(void)other;
	return *this;
}

Point::~Point(){}

Fixed Point::getX(void) const
{
	return this->x;
}

Fixed Point::getY(void) const
{
	return this->y;
}
