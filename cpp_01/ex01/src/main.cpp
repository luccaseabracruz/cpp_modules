/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 18:13:00 by lseabra-          #+#    #+#             */
/*   Updated: 2026/08/17 09:57:18 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Zombie.hpp"
#include "Zombie.hpp"

static bool	isValidDigit(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

int	main(int argc, char *argv[])
{
	Zombie	*horde;
	int		n = 5;
	std::string	name = "Jarbas";

	if (argc > 1)
	{
		if (isValidDigit(argv[1]))
			std::istringstream(argv[1]) >> n;
		else
		{
			std::cout << "[Error]: invalid argument: '" << argv[1] << "'\n";
			return (1);
		}
	}
	if (argc > 2)
		name = argv[2];
	horde = zombieHorde(n, name);
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
}
