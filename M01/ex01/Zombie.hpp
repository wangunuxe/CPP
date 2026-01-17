/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:08:20 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:08:23 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include<string>
# include<iostream>

class Zombie
{
private:
	std::string _name;
public:
    Zombie();
    ~Zombie();
	void	setName(std::string name);
	void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
