/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 13:47:28 by lseabra-          #+#    #+#             */
/*   Updated: 2026/09/23 13:52:53 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests.hpp"

void	printSection(const std::string& title)
{
	std::cout	<< "------------------------------------------\n"
				<< "--- " << title << "\n"
				<< "------------------------------------------\n";
}

void	printHeader(const std::string& title)
{
	std::cout	<< "===================================================================\n"
				<< "= " << title << "\n"
				<< "===================================================================\n";
}

int	test(int (*function)(void), const std::string& title)
{
	if (function() != 0)
	{
		std::cout << title << ": >>> STATUS: FAIL\n";
		return (-1);
	}
	std::cout << title << ": >>> STATUS: SUCCESS\n";
	return (0);
}
