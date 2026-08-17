/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:18:55 by lucca             #+#    #+#             */
/*   Updated: 2026/08/17 12:50:06 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;

	public:
		HumanB(const std::string& name);
		~HumanB();
		void	attack() const;
		void	setWeapon(Weapon &newWeapon);
};

#endif
