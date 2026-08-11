/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:51:18 by lseabra-          #+#    #+#             */
/*   Updated: 2026/08/10 16:54:13 by lucca            ###   ########.fr       */
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
			book.searchContact();
		}
		else if (input == "EXIT")
		{
			std::cout << "Goodbye!\n";
			break ;
		}
		else
		{
			putErr("invalid operation: " + input + "\n");
		}
	}
	return (0);
};
