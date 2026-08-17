/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:33:56 by lucca             #+#    #+#             */
/*   Updated: 2026/08/17 12:48:55 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(const std::string& newName, const Weapon& weapon)
	: name(newName), weapon(weapon)
{
};
HumanA::~HumanA(){};

void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << '\n';
}
