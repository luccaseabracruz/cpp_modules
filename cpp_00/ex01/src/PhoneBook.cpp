/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:31:06 by lucca             #+#    #+#             */
/*   Updated: 2026/08/11 14:09:59 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"
#include "utils.hpp"
#include "colors.hpp"
#include "validate.hpp"


PhoneBook::PhoneBook(): counter_(0)
{
};

PhoneBook::~PhoneBook()
{
}

bool	PhoneBook::addContact()
{
	Contact	contact;

	if (!createContact(contact))
		return false;
	contacts_[counter_ % 8] = contact;
	counter_++;
	std::cout << GREEN << "Contact successfully registered.\n" << RESET;
	return true;
}

void	PhoneBook::putItem_(const std::string& str, bool endPipe) const
{
	std::string item;

	if (str.length() > 10)
	{
		item = str.substr(0, 9) + ".";
	}
	else
		item = str;
	std::cout << std::right << std::setw(10) << item;
	if (endPipe)
		std::cout << "|";
}
void	PhoneBook::displayContacts_() const
{
	int	limit;

	if (counter_ < 8)
		limit = counter_;
	else
		limit = 8;
	putItem_("index", true);
	putItem_("first name", true);
	putItem_("last name", true);
	putItem_("nickname", false);
	std::cout << '\n';
	for (int i = 0; i < limit ; i++)
	{
		std::cout << std::right << std::setw(10) << i << "|";
		putItem_(contacts_[i].getFirstName(), true);
		putItem_(contacts_[i].getLastName(), true);
		putItem_(contacts_[i].getNickname(), false);
		std::cout << '\n';
	}
}

static void	displayContactInfo(const Contact contact)
{
	std::cout << GREEN << "First Name: " << RESET << contact.getFirstName() << '\n';
	std::cout << GREEN << "Last Name: " << RESET << contact.getLastName() << '\n';
	std::cout << GREEN << "Nickname: " << RESET << contact.getNickname() << '\n';
	std::cout << GREEN << "Phone Number: " << RESET << contact.getPhoneNumber() << '\n';
	std::cout << GREEN << "Darkest Secret: " << RESET << contact.getDarkestSecret() << '\n';
}

bool	PhoneBook::searchContact() const
{
	std::string	input;

	if (counter_ < 1)
	{
		std::cout << YELLOW << "There are no registered contacts.\n" << RESET;
		return true;
	}
	displayContacts_();
	if (!getInput("Select the index of target contact: ", input) || !validateIndex(input, counter_))
		return false;
	displayContactInfo(contacts_[(input[0] - '0')]);
	return true;
}
