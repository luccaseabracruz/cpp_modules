/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:31:06 by lucca             #+#    #+#             */
/*   Updated: 2026/08/08 10:43:28 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "utils.hpp"


PhoneBook::PhoneBook(): counter_(0){};

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
	return true;
}