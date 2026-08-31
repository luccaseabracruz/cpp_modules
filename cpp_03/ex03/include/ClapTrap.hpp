/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:52:16 by lucca             #+#    #+#             */
/*   Updated: 2026/08/31 13:08:47 by lucca            ###   ########.fr       */
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
	protected:
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
		
		// Setters
		// void	setName(const std::string& name);
		// void	setHitPoints(unsigned int amount);
		// void	setEnergyPoints(unsigned int amount);
		// void	setAttackDamage(unsigned int amount);
};

#endif