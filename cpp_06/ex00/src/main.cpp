/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 19:22:28 by lucca             #+#    #+#             */
/*   Updated: 2026/10/07 14:52:00 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc <= 1 || argc > 2)
	{
		std::cerr << "Error: invalid number of arguments (expected one).\n";
		return (-1);
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (-1);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (-1);
	}
	return (0);
}
