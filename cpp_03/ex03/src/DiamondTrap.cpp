/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:44:53 by lucca             #+#    #+#             */
/*   Updated: 2026/08/31 18:43:00 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

//============================================================================//
//                         SPECIAL MEMBER FUNCTIONS                           //
//============================================================================//

DiamondTrap::DiamondTrap(void): ClapTrap("Noname_clap_name"), name_("Noname")
{
	std::cout << DT_PREFIX << DiamondTrap::name_ << " Default Constructor being called.\n";
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 30;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"), name_(name)
{
	std::cout << DT_PREFIX << DiamondTrap::name_ << " Constructor called.\n";
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other.getClapName()), ScavTrap(), FlagTrap(), name_(other.getName())
{
	std::cout << DT_PREFIX << DiamondTrap::name_ << " Copy Constructor called.\n";
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << DT_PREFIX << DiamondTrap::name_ << " Copy Assignment Operator called.\n";
	if (this != &other)
	{
		ClapTrap::name_ = other.getClapName();
		DiamondTrap::name_ = other.getName();
		hitPoints_ = other.getHitPoints();
		energyPoints_ = other.getEnergyPoints();
		attackDamage_ = other.getAttackDamage();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << DT_PREFIX << DiamondTrap::name_ << " Destructor called.\n";
};

//============================================================================//
//                                 ACTION                                     //
//============================================================================//

// Not strictly necessary: override-dominance rules already make
// ScavTrap::attack() win, since it is more derived than ClapTrap::attack()
// and FragTrap does not override attack(). Explicit here for clarity.
// void DiamondTrap::attack(const std::string& target) {
// 	ScavTrap::attack(target);
// }


//============================================================================//
//                                  GETTERS                                   //
//============================================================================//

std::string	DiamondTrap::getName(void)	const
{
	return (DiamondTrap::name_);
}

std::string	DiamondTrap::getClapName(void)	const
{
	return (ClapTrap::name_);
}

//============================================================================//
//                                  ABILITY                                   //
//============================================================================//

void DiamondTrap::whoAmI(void)	const
{
	std::cout	<< DT_PREFIX << "name is " << DiamondTrap::name_ << " and " 
				<< CT_PREFIX << "name is " << ClapTrap::name_ << ".\n";
}
