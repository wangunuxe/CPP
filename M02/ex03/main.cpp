/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:12:29 by jili              #+#    #+#             */
/*   Updated: 2026/01/18 16:45:45 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A Fixed object represents a number stored using fixed-point representation.

// A Point object represents a location or a position in 2D space using two fixed-point numbers.
// So these two data numbers (Fixed const x and Fixed const y) are : The coordinates of the point: 
// x --> horizontal position
// y --> vertical position

// bsp is a function that answers : is this point stricly inside this triangle?

#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(2, 2);
	Point outside(10, 10);
	Point edge(5, 0);
	Point vertex(0, 0);

	std::cout << "inside  : " << bsp(a,b,c,inside)  << std::endl;
	std::cout << "outside : " << bsp(a,b,c,outside) << std::endl;
	std::cout << "edge    : " << bsp(a,b,c,edge)    << std::endl;
	std::cout << "vertex  : " << bsp(a,b,c,vertex)  << std::endl;
}

