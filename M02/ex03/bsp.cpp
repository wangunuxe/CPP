/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:28:44 by jili              #+#    #+#             */
/*   Updated: 2026/01/21 11:28:47 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


static Fixed cross(Point const& a, Point const& b, Point const& p)
{
	// (b - a) x (p - a)
    Fixed bx = b.getX() - a.getX();
    Fixed by = b.getY() - a.getY();
    Fixed px = p.getX() - a.getX();
    Fixed py = p.getY() - a.getY();
    return bx * py - by * px;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)//all four parameters are passed by value, so the copy constructor is called behind the scenes
{
	Fixed ab = cross(a, b, point);
	Fixed bc = cross(b, c, point);
	Fixed ca = cross(c, a, point);

	//on the edge or vertex
	if (ab == Fixed(0) || bc == Fixed(0) || ca == Fixed(0))
		return false;
	//A point is inside a triangle if:It is on the SAME side of ALL THREE edges.
	// Check if all results are positive
	else if (ab > Fixed(0) && bc > Fixed(0) && ca > Fixed(0))
		return true;

	// Check if all results are negative
	else if (ab < Fixed(0) && bc < Fixed(0) && ca < Fixed(0))
		return true;

	// Otherwise, the point is outside
	return false;
}

