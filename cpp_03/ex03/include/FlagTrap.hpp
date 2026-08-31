/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 18:20:52 by lucca             #+#    #+#             */
/*   Updated: 2026/08/31 13:07:10 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

//============================================================================//
//                                  MACROS                                    //
//============================================================================//
# define FT_PREFIX "[FlagTrap] "

//============================================================================//
//                                  CLASSES                                   //
//============================================================================//
class	FlagTrap: virtual public ClapTrap
{
	public:
		// Special Member functions
		FlagTrap(void);
		FlagTrap(const std::string& name);
		FlagTrap(const FlagTrap& other);
		FlagTrap&	operator=(const FlagTrap& other);
		~FlagTrap(void);

		// Ability
		void highFivesGuys(void);
};

#endif
