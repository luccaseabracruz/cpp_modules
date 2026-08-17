/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:15:56 by lucca             #+#    #+#             */
/*   Updated: 2026/08/17 15:41:17 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string		name;
		const Weapon&	weapon;

	public:
		HumanA(const std::string& name, const Weapon& weapon);
		~HumanA();
		void	attack() const;
};

#endif
