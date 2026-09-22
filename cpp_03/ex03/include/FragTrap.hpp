/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 18:20:52 by lucca             #+#    #+#             */
/*   Updated: 2026/09/22 17:36:35 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

//============================================================================//
//                                  MACROS                                    //
//============================================================================//
# define FT_PREFIX "[FragTrap] "

//============================================================================//
//                                  CLASSES                                   //
//============================================================================//
class	FragTrap: virtual public ClapTrap
{
	public:
		// Special Member functions
		FragTrap(void);
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap& other);
		~FragTrap(void);

		// Ability
		void highFivesGuys(void);
};

#endif
