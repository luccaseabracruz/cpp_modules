/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 11:10:05 by lucca             #+#    #+#             */
/*   Updated: 2026/08/27 13:56:38 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits.h>
#include "ClapTrap.hpp"

//============================================================================//
//                         SPECIAL MEMBER FUNCTIONS                           //
//============================================================================//
ClapTrap::ClapTrap(void)
	: name_("Noname"), hitPoints_(10),
	energyPoints_(10), attackDamage_(0)
{
	std::cout << CT_PREFIX << name_ << " Default Constructor called.\n";
}

ClapTrap::ClapTrap(const std::string& name)
	: name_(name), hitPoints_(10),
	energyPoints_(10), attackDamage_(0)
{
	std::cout << CT_PREFIX << name_ << " Constructor called.\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << CT_PREFIX << name_ << " Constructor called.\n";
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << CT_PREFIX << name_ << " Assignment Operator Constructor called.\n";
	this->name_ = other.getName();
	this->hitPoints_ = other.getHitPoints();
	this->energyPoints_ = other.getEnergyPoints();
	this->attackDamage_ = other.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << CT_PREFIX << name_ << " Destructor called.\n";
}

//============================================================================//
//                                 ACTIONS                                    //
//============================================================================//
void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints_ == 0)
	{
		std::cout << CT_PREFIX << name_ << " is dead. Impossible to attack.\n";
		return ;
	}
	else if (energyPoints_ == 0)
	{
		std::cout << CT_PREFIX << name_ << " has no energy for the attack.\n";
		return ;
	}
	--energyPoints_;
	std::cout	<< CT_PREFIX << name_ << " attacks " << target
				<< ", causing " << attackDamage_ << " points of damage!\n";
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints_ == 0)
	{
		std::cout	<< CT_PREFIX << name_
					<< " is already dead. Can't take more damage.\n";
		return ;
	}
	if (amount > hitPoints_)
		hitPoints_ = 0;
	else
		hitPoints_ -= amount;
	std::cout	<< CT_PREFIX << name_ << " took " << amount
	<< " points of damage; Current Hit Points: " << hitPoints_ << '\n';
	if (hitPoints_ == 0)
		std::cout << CT_PREFIX << name_ << " died.\n";

}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints_ == 0)
	{
		std::cout << CT_PREFIX << name_ << " has no energy to be repaired.\n";
		return ;
	}
	if (amount > UINT_MAX - hitPoints_)
		hitPoints_ = UINT_MAX;
	else
		hitPoints_ += amount;
	std::cout	<< CT_PREFIX << name_ << " got a repair of " << amount
				<< " Hit Points; Current Hit Points: " << hitPoints_ << '\n';
}

//============================================================================//
//                                 GETTERS                                    //
//============================================================================//
std::string	ClapTrap::getName(void) const
{
	return (name_);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (hitPoints_);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (energyPoints_);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (attackDamage_);
}


//============================================================================//
//                                 SETTERS                                    //
//============================================================================//
// void	ClapTrap::setName(const std::string& name)
// {
	
// }

// void	ClapTrap::setHitPoints(int amount)
// {
	
// }

// void	ClapTrap::setEnergyPoints(int amount)
// {
	
// }

// void	ClapTrap::setAttackDamage(int amount)
// {
	
// }
