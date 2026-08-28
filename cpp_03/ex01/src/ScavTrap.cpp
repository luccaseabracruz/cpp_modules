/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:40:42 by lucca             #+#    #+#             */
/*   Updated: 2026/08/28 20:37:07 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

//============================================================================//
//                         SPECIAL MEMBER FUNCTIONS                           //
//============================================================================//
ScavTrap::ScavTrap(void)
{
	std::cout << ST_PREFIX << name_ << " Default Constructor called\n";
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
	std::cout << ST_PREFIX << name_ << " Default Constructor called.\n";
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other.getName())
{
	std::cout << ST_PREFIX << name_ << " Copy Constructor called.\n";
	*this = other;
}
ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << ST_PREFIX << name_ << " Copy Asignment Operator called.\n";
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << ST_PREFIX << name_ << " Destructor called.\n";
}

//============================================================================//
//                            Member Functions                                //
//============================================================================//
void	ScavTrap::attack(const std::string& target)
{
	if (hitPoints_ == 0)
	{
		std::cout << ST_PREFIX << name_ << " is dead. Impossible to attack.\n";
		return ;
	}
	else if (energyPoints_ == 0)
	{
		std::cout << ST_PREFIX << name_ << " has no energy for the attack.\n";
		return ;
	}
	--energyPoints_;
	std::cout	<< ST_PREFIX << name_ << " attacks " << target
				<< ", causing " << attackDamage_ << " points of damage!\n";
}

//============================================================================//
//                                 ABILITY                                    //
//============================================================================//

void	ScavTrap::guardGate(void)
{
	std::cout << ST_PREFIX << name_ << " is now in Gate keeper mode.\n";
}
