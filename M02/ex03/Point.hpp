/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:29:09 by jili              #+#    #+#             */
/*   Updated: 2026/01/21 11:29:11 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"
class Point
{
private:
	const Fixed	x;
	const Fixed y;
public:
	Point();
	Point(const float a, const float b);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();

	Fixed getX(void) const;
	Fixed getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
#endif
