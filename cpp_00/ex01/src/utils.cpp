/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:33:26 by lucca             #+#    #+#             */
/*   Updated: 2026/08/10 14:00:18 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "utils.hpp"
#include "validate.hpp"
#include "colors.hpp"

static bool	getField(const std::string& msg, std::string& field, Validator isValid)
{
	while (true)
	{
		if (!getInput(msg, field))
		{
			if (std::cin.eof() == true)
				return false;
			continue ;
		}
		else if (isValid && !isValid(field))
			continue ;
		else
			break ;
	}
	return true;
}

bool	createContact(Contact contact)
{
	std::string	firstName, lastName, nickname, phoneNumber, darkestSecret;

	if (!getField("First Name: ", firstName, &isNotEmptyField)
		|| !getField("Last Name: ", lastName, &isNotEmptyField)
		|| !getField("Nickname: ", nickname, &isNotEmptyField)
		|| !getField("Phone Number: ", phoneNumber, &validatePhoneNumber)
		|| !getField("Darkest Secret: ", darkestSecret, &isNotEmptyField))
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

bool	putErr(const std::string& msg)
{
	std::cerr << RED << ERR_PREFIX << msg << RESET;
	return false;
}
