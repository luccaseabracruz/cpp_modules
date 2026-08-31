/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 18:21:52 by lucca             #+#    #+#             */
/*   Updated: 2026/08/31 15:45:06 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FlagTrap.hpp"

//============================================================================//
//                         SPECIAL MEMBER FUNCTIONS                           //
//============================================================================//
FlagTrap::FlagTrap(void): ClapTrap("Noname")
{
	std::cout << FT_PREFIX << name_ << " Default Constructor called.\n";
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
}

FlagTrap::FlagTrap(const std::string& name): ClapTrap(name)
{
	std::cout << FT_PREFIX << name_ << " Constructor called.\n";
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
}

FlagTrap::FlagTrap(const FlagTrap& other): ClapTrap()
{
	std::cout << FT_PREFIX << name_ << " Copy Constructor called.\n";
	*this = other;
}

FlagTrap&	FlagTrap::operator=(const FlagTrap& other)
{
	std::cout << FT_PREFIX << name_ << " Assignment Operator called.\n";
	if (this != &other)
	{
		this->name_ = other.getName();
		this->hitPoints_ = other.getHitPoints();
		this->energyPoints_ = other.getEnergyPoints();
		this->attackDamage_ = other.getAttackDamage();
	}
	return (*this);
}

FlagTrap::~FlagTrap(void)
{
	std::cout << FT_PREFIX << name_ << " Destructor called.\n";
}

//============================================================================//
//                                 ABILITY                                    //
//============================================================================//
void	FlagTrap::highFivesGuys(void)
{
	std::cout << "Be kind guys. Give " << FT_PREFIX << name_ << " a HIGH FIVE :)\n";
}
