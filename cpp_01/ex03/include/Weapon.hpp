/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:14:33 by lucca             #+#    #+#             */
/*   Updated: 2026/08/17 12:53:01 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class	Weapon
{
	private:
		std::string	type;

	public:
		Weapon(const std::string& newType);
		~Weapon();
		const std::string&	getType() const;
		void				setType(const std::string& newType);
};

#endif
