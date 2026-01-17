/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarL.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:12:13 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:12:27 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarL.hpp"

HarL::HarL(){}

HarL::~HarL(){}

void    HarL::debug(void)
{
	std::cout << "[ DEBUG ]\n"
			<< "I love having extra bacon for my "
			<< "7XL-double-cheese-triple-pickle-specialketchup burger.\n"
			<< std::endl;
}

void HarL::info(void)
{
	std::cout
		<< "[ INFO ]\n"
		<< "I cannot believe adding extra bacon costs more money.\n"
		<< std::endl;
}

void HarL::warning(void)
{
	std::cout
		<< "[ WARNING ]\n"
		<< "I think I deserve to have some extra bacon for free.\n"
		<< std::endl;
}

void HarL::error(void)
{
	std::cout
		<< "[ ERROR ]\n"
		<< "This is unacceptable! I want to speak to the manager now.\n"
		<< std::endl;
}

void HarL::complain(std::string level)
{
	std::string levels[4] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};//an array of strings
	void (HarL::*functions[4])(void) = 
	{
		&HarL::debug,
		&HarL::info,
		&HarL::warning,
		&HarL::error
	};//an array of 4 pointers to member functions of HarL that take no parameters and return void.
	//void (*funcs[4])(int):array of 4 pointers to functions taking int and returning void
	//create two parallel arrays used as a dispatch table
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}
}

