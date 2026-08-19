/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:04:44 by lucca             #+#    #+#             */
/*   Updated: 2026/08/19 16:59:27 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

typedef enum	level_e
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
}	level_t;

class	Harl
{
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

typedef	void	(Harl::*HarlPrivMemFun)(void);

#endif
