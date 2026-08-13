/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 18:21:01 by lseabra-          #+#    #+#             */
/*   Updated: 2026/08/13 18:21:52 by lseabra-         ###   ########.fr       */
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
		void announce( void );
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
