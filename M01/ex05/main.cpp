/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:12:00 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:12:02 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarL.hpp"

int main(void)
{
	HarL harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	return 0;
}
