/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:52:16 by lucca             #+#    #+#             */
/*   Updated: 2026/09/22 13:10:03 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

//============================================================================//
//                                  MACROS                                    //
//============================================================================//
# define CT_PREFIX "[ClapTrap] "

//============================================================================//
//                                  CLASSES                                   //
//============================================================================//

class	ClapTrap
{
	private:
		// Private Member Variables
		std::string		name_;
		unsigned int	hitPoints_;
		unsigned int	energyPoints_;
		unsigned int	attackDamage_;

	public:
		// Special Members
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap&	operator=(const ClapTrap& other);
		~ClapTrap(void);
		
		// Actions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		// Getters
		std::string		getName(void)			const;
		unsigned int	getHitPoints(void)		const;
		unsigned int	getEnergyPoints(void)	const;
		unsigned int	getAttackDamage(void)	const;
};

#endif