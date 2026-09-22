/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:52:04 by lucca             #+#    #+#             */
/*   Updated: 2026/09/22 17:31:36 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "tests.hpp"

int	main(int argc, char* argv[])
{
	if (argc > 1 && std::string(argv[1]) == "-a")
	{
		testClapTrap();
		testScavTrap();
		testFragTrap();
	}
	testDiamondTrap();
	return (0);
}
