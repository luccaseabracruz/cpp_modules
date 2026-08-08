/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:33:26 by lucca             #+#    #+#             */
/*   Updated: 2026/08/08 10:49:37 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "utils.hpp"

static bool	isEmptySpaceStr(const std::string& str)
{
	size_t	len = str.length();

	if (len < 1)
		return true;
	for (size_t i = 0; i < len; i++)
	{
		if (!isspace(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

static bool	getField(const std::string& msg, std::string& field)
{
	while (true)
	{
		if (!getInput(msg, field))
		{
			if (std::cin.eof() == true)
				return false;
			continue ;
		}
		else if (isEmptySpaceStr(field))
			std::cout << ERR_PREFIX << "this field cannot be empty.\n";
		else
			break ;
	}
	return true;
}

bool	createContact(Contact contact)
{
	std::string	firstName, lastName, nickname, phoneNumber, darkestSecret;

	if (!getField("First Name: ", firstName)
		|| !getField("Last Name: ", lastName)
		|| !getField("Nickname: ", nickname)
		|| !getField("Phone Number: ", phoneNumber)
		|| !getField("Darkest Secret: ", darkestSecret))
	{
		return false;
	}
	contact = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	return true;
}

bool	getInput(const std::string& msg, std::string& input)
{
	std::cout << msg << " ";
	if (!std::getline(std::cin, input) || std::cin.eof() == true)
		return false;
	return true;
};
