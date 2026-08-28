/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:31:11 by lucca             #+#    #+#             */
/*   Updated: 2026/08/27 17:04:18 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

//============================================================================//
//                                  MACROS                                    //
//============================================================================//
# define ST_PREFIX "[ScavTrap] "

//============================================================================//
//                                  CLASSES                                   //
//============================================================================//

class	ScavTrap: public ClapTrap
{
	private:

	public:
		// Special Member Functions
		ScavTrap(void);
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& other);
		ScavTrap&	operator=(const ScavTrap& other);
		~ScavTrap(void);

		// Ability
		void	guardGate(void);
};

#endif