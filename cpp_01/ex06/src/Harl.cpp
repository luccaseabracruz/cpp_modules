/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:05:44 by lucca             #+#    #+#             */
/*   Updated: 2026/08/19 18:12:25 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl(){};

Harl::~Harl(){};

void	Harl::debug()
{
	std::cout << "[ DEBUG ]\n I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << "\n\n";
}

void	Harl::info()
{
	std::cout << "[ INFO ]\n I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << "\n\n";
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]\n I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << "\n\n";
}

void	Harl::error()
{
	std::cout << "[ ERROR ]\n This is unacceptable! I want to speak to the manager now." << "\n\n";
}

void	Harl::complain(std::string level)
{
	const std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int					level_idx = -1;

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			level_idx = i;
			break ;
		}
	}
	switch (level_idx)
	{
		case 0:
			debug();
		// fall through
		case 1:
			info();
		// fall through
		case 2:
			warning();
		// fall through
		case 3:
		{
			error();
			break ;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
