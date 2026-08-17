/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:43:42 by lucca             #+#    #+#             */
/*   Updated: 2026/08/17 12:50:09 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string& newName)
	: name(newName), weapon(NULL)
{
};
HumanB::~HumanB()
{
};

void	HumanB::attack() const
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << '\n';
	else
		std::cout << name << " does not have a weapon\n";
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}
