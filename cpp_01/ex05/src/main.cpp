/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:04:33 by lucca             #+#    #+#             */
/*   Updated: 2026/08/19 15:49:37 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "[Error] Wrong number of arguments: got " << argc << " expected 2.\n";
		return (1);
	}
	Harl	harl;
	const std::string level = argv[1];
	harl.complain(level);
	return (0);
}
