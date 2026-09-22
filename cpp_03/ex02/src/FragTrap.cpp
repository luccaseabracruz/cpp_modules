/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 18:21:52 by lucca             #+#    #+#             */
/*   Updated: 2026/09/22 17:35:00 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

//============================================================================//
//                         SPECIAL MEMBER FUNCTIONS                           //
//============================================================================//
FragTrap::FragTrap(void): ClapTrap("Noname")
{
	std::cout << FT_PREFIX << name_ << " Default Constructor called.\n";
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	std::cout << FT_PREFIX << name_ << " Constructor called.\n";
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap()
{
	std::cout << FT_PREFIX << name_ << " Copy Constructor called.\n";
	*this = other;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
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

FragTrap::~FragTrap(void)
{
	std::cout << FT_PREFIX << name_ << " Destructor called.\n";
}

//============================================================================//
//                                 ABILITY                                    //
//============================================================================//
void	FragTrap::highFivesGuys(void)
{
	std::cout << "Be kind guys. Give " << FT_PREFIX << name_ << " a HIGH FIVE :)\n";
}
