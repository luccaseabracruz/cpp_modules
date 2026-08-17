/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:13:31 by lucca             #+#    #+#             */
/*   Updated: 2026/08/17 12:49:18 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& newType): type(newType)
{
};

Weapon::~Weapon()
{
};

const std::string& Weapon::getType() const
{
	return type;
}

void	Weapon::setType(const std::string& newType)
{
	type = newType;
}
