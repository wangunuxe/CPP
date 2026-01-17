/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:13:03 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:13:04 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarL.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	int	levelIndex = -1;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == argv[1])
		{
			levelIndex = i;
			break;
		}	
	}
	
	HarL H;
	switch (levelIndex)
	{
		case 0:
			H.debug();
			/* fall through */
		case 1:
			H.info();
			/* fall through */
		case 2:
			H.warning();
			/* fall through */
		case 3:
			H.error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}

//A switch jumps to the matching case label,then executes ALL code BELOW it,until it sees a break or the end.
//In C++98, intentional fallthrough must be documented with a comment, or -Werror will kill your build.
