/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 13:03:59 by lucca             #+#    #+#             */
/*   Updated: 2026/08/31 15:28:07 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

//============================================================================//
//                                  MACROS                                    //
//============================================================================//
# define DT_PREFIX "[DiamondTrap] "

//============================================================================//
//                                  CLASSES                                   //
//============================================================================//
class	DiamondTrap: public ScavTrap, public FlagTrap
{
	private:
		std::string	name_;

	public:
		// Special Members
		DiamondTrap(void);
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap&	operator=(const DiamondTrap& other);
		~DiamondTrap(void);

		// Actions
		// void DiamondTrap::attack(const std::string& target); // Not mandatory because of the override-dominance rule
		// Ability
		void whoAmI(void);
};

#endif
