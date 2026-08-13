/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:39:21 by lseabra-          #+#    #+#             */
/*   Updated: 2026/08/13 19:43:41 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie *z = new Zombie(name);
	if (!z)
	{
		std::cout << "Error: Zombie allocation failed.\n";
		return (NULL);
	}
	return (z);
}
