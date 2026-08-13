/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 18:13:00 by lseabra-          #+#    #+#             */
/*   Updated: 2026/08/13 20:24:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
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
	int	n = argc + 1;
	if (argc > 1)
	{
		if (isValidDigit(argv[1]))
		{
			std::istringstream(argv[1]) >> n;
			std::cout << "N = " << n << "\n";
		}
		else
		{
			std::cout << "[Error]: invalid argument: '" << argv[1] << "'\n";
			std::cout << "Using default value for N (argc + 1): " << n << '\n';
		}
	}
}
