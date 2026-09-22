/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 13:03:59 by lucca             #+#    #+#             */
/*   Updated: 2026/09/22 17:30:54 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

//============================================================================//
//                                  MACROS                                    //
//============================================================================//
# define DT_PREFIX "[DiamondTrap] "

//============================================================================//
//                                  CLASSES                                   //
//============================================================================//
class	DiamondTrap: public ScavTrap, public FragTrap
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
		// void attack(const std::string& target); // Not mandatory because of the override-dominance rule

		// Getters
		std::string	getName(void)		const;

		// Ability
		void whoAmI(void)	const;
};

#endif
