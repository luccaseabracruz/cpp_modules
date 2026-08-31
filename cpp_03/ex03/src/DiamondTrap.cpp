/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:44:53 by lucca             #+#    #+#             */
/*   Updated: 2026/08/31 15:44:40 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

//============================================================================//
//                         SPECIAL MEMBER FUNCTIONS                           //
//============================================================================//

DiamondTrap::DiamondTrap(void): ClapTrap("Noname"), name_("Noname")
{
	std::cout << DT_PREFIX << " Default Constructor being called.\n";
	ClapTrap::name_.append("_clap_name");
	hitPoints_ = FlagTrap::hitPoints_;
	energyPoints_ = ScavTrap::energyPoints_;
	attackDamage_ = FlagTrap::attackDamage_;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name), name_(name)
{
	std::cout << DT_PREFIX << " Constructor called.\n";
	ClapTrap::name_.append("_clap_name");
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other.getName()), ScavTrap(), FlagTrap(), name_(other.getName())
{
	std::cout << DT_PREFIX << " Copy Constructor called.\n";
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << DT_PREFIX << " Copy Assignment Operator called.\n";
	if (this != &other)
	{
		ClapTrap::name_ = other.ClapTrap::getName();
		name_ = other.DiamondTrap::getName();
		hitPoints_ = other.getHitPoints();
		energyPoints_ = other.getEnergyPoints();
		attackDamage_ = other.getAttackDamage();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << DT_PREFIX << " Destructor called.\n";
};

//============================================================================//
//                                 ABILITY                                    //
//============================================================================//

// Not strictly necessary: override-dominance rules already make
// ScavTrap::attack() win, since it is more derived than ClapTrap::attack()
// and FragTrap does not override attack(). Explicit here for clarity.
// void DiamondTrap::attack(const std::string& target) {
// 	ScavTrap::attack(target);
// }

//============================================================================//
//                                 ABILITY                                    //
//============================================================================//

void DiamondTrap::whoAmI(void)
{
	std::cout	<< DT_PREFIX << "name is " << DiamondTrap::name_ << " and " 
				<< CT_PREFIX << "name is " << ClapTrap::name_ << ".\n";
}
