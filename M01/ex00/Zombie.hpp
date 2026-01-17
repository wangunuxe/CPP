/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:06:50 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:06:53 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class	Zombie
{
private:
	std::string name;
public:
	Zombie();
	Zombie(std::string n);
	~Zombie();
	void announce(void);
};

void	randomChump(std::string name);
Zombie* newZombie(std::string name);
#endif
