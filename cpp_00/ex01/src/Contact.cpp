/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:08:44 by lucca             #+#    #+#             */
/*   Updated: 2026/08/10 14:42:52 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "utils.hpp"

Contact::Contact(void)
		:	firstName_(""), lastName_(""), nickname_(""),
			phoneNumber_(""), darkestSecret_("")
{}

Contact::Contact(const std::string& firstName, const std::string& lastName, 
				const std::string& nickname, const std::string& phoneNumber,
				const std::string& darkestSecret)
		:	firstName_(firstName), lastName_(lastName), nickname_(nickname),
			phoneNumber_(phoneNumber),	darkestSecret_(darkestSecret)
{}

Contact::~Contact(){}

std::string	Contact::getFirstName() const
{
	return firstName_;
}

std::string	Contact::getLastName() const
{
	return lastName_;
}

std::string	Contact::getNickname() const
{
	return nickname_;
}

std::string	Contact::getPhoneNumber() const
{
	return phoneNumber_;
}

