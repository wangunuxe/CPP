/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarL.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:13:30 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:13:33 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <cstring>

class HarL
{
public:
	HarL();
	~HarL();
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif
