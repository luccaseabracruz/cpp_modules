/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:33:35 by lseabra-          #+#    #+#             */
/*   Updated: 2026/08/13 18:21:45 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): name_(name){};

Zombie::~Zombie()
{
	std::cout << name_ << " destroyed\n";
};

void	Zombie::announce(void)
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}
