/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:33:35 by lseabra-          #+#    #+#             */
/*   Updated: 2026/08/19 18:30:30 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string newName): name(newName){};
Zombie::Zombie(void): name(""){};

Zombie::~Zombie()
{
	std::cout << name << " destroyed\n";
};

void	Zombie::announce(void) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(const std::string& newName)
{
	name = newName;
}
