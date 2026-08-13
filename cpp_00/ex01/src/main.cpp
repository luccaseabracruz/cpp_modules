/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:51:18 by lseabra-          #+#    #+#             */
/*   Updated: 2026/08/13 14:50:53 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"

int	main(void)
{
	PhoneBook book;
	
	while (true)
	{
		std::string	input;

		if(!getInput(MSG_OPERATION, input))
			break ;
		else if (input == "ADD")
		{
			if (!book.addContact())
				break ;
		}
		else if (input == "SEARCH")
		{
			if (!book.searchContact())
				break ;
		}
		else if (input == "EXIT")
		{
			std::cout << "Goodbye!";
			break ;
		}
		else
		{
			putErr("invalid operation: " + input + '\n');
		}
	}
	std::cout << '\n';
	return (0);
};
