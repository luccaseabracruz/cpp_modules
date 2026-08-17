/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:33:35 by lseabra-          #+#    #+#             */
/*   Updated: 2026/08/17 15:10:33 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): name_(name){};

Zombie::~Zombie()
{
	std::cout << name_ << " destroyed\n";
};

void	Zombie::announce(void) const
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}
