/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:51:18 by lseabra-          #+#    #+#             */
/*   Updated: 2026/07/29 19:08:57 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static std::string	ft_input(void)
{
	std::string	input;

	std::cout << "Choose a command (ADD | SEARCH | EXIT): ";
	std::cin >> input;
	return (input);
};

static ft_new_contact()
{
	
}

int	main(void)
{
	std::string	input = ft_input();
	PhoneBook	book;
	int			counter = 0;

	if (input == "ADD")
		std::cout << "ADD" << std::endl;
	else if (input == "SEARCH")
		std::cout << "SEARCH" << std::endl;
	else if (input == "EXIT")
		std::cout << "EXIT" << std::endl;
};
