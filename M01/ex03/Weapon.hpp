/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:10:26 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:10:28 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
class Weapon
{
private:
	std::string type;
public:
	Weapon();
	~Weapon();
	Weapon(const std::string& type);
	const std::string& getType() const;
	void setType(const std::string& type);
};

#endif
