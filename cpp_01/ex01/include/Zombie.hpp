/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 18:21:01 by lseabra-          #+#    #+#             */
/*   Updated: 2026/08/19 18:30:43 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(std::string name);
		Zombie(void);
		~Zombie();
		void	announce( void ) const;
		void	set_name(const std::string& name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
