/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarL.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:12:39 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:12:41 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class HarL
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
public:
	HarL();
	~HarL();
	void complain(std::string level);
};

#endif
