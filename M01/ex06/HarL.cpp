/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarL.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:13:13 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:13:23 by jili             ###   ########.fr       */
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


