/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 18:21:04 by lseabra-          #+#    #+#             */
/*   Updated: 2026/08/17 15:09:23 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string name_;

	public:
		Zombie(std::string name);
		~Zombie();
		void announce(void) const;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif