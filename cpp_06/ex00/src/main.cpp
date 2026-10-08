/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 19:22:28 by lucca             #+#    #+#             */
/*   Updated: 2026/10/08 16:40:15 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		if (argc <= 1 || argc > 2)
			throw std::invalid_argument("expected one argument");
		ScalarConverter::convert(argv[1]);
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << "Error: invalid argument: " << e.what() << '\n';
		return (-1);
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "Error: out of range" << e.what() << '\n';
		return (-1);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (-1);
	}
	return (0);
}
