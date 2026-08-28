/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 18:21:52 by lucca             #+#    #+#             */
/*   Updated: 2026/08/28 20:11:25 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FlagTrap.hpp"

//============================================================================//
//                         SPECIAL MEMBER FUNCTIONS                           //
//============================================================================//
FlagTrap::FlagTrap(void): ClapTrap("Noname")
{
	std::cout << FT_PREFIX << name_ << " Default Constructor being called.\n";
}

FlagTrap::FlagTrap(const std::string name)
{
	std::cout << FT_PREFIX << name_ << " Constructor being called.\n";
}

FlagTrap::FlagTrap(const FlagTrap& other)
{
	std::cout << FT_PREFIX << name_ << " Copy Constructor being called.\n";
}

FlagTrap&	FlagTrap::operator=(const FlagTrap& other)
{
	std::cout << FT_PREFIX << name_ << " Assignment Operator being called.\n";
}

FlagTrap::~FlagTrap(void)
{
	std::cout << FT_PREFIX << name_ << " Desctructor being called.\n";
}

//============================================================================//
//                                 ABILITY                                    //
//============================================================================//
void	FlagTrap::highFivesGuys(void)
{
	
}