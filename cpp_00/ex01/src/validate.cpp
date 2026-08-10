/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 11:25:50 by lucca             #+#    #+#             */
/*   Updated: 2026/08/10 14:07:09 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "utils.hpp"
#include "colors.hpp"

bool	isNotEmptyField(const std::string& str)
{
	size_t	len = str.length();

	for (size_t i = 0; i < len; i++)
	{
		if (!isspace(static_cast<unsigned char>(str[i])))
			return true;
	}
	putErr("this field cannot be empty.\n");
	return false;
}


bool	validatePhoneNumber(const std::string& phoneNumber)
{
	size_t	len = phoneNumber.length();
	size_t	i = 0;

	if (!isNotEmptyField(phoneNumber))
		return false;
	while (i < len)
	{
		if (i == 0 && phoneNumber[i] == '+')
			i++;
		if (!isdigit(phoneNumber[i]))
		{
			putErr("invalid Phone Number: '" + phoneNumber + "'\n");
			return false;
		}
		i++;
	}
	return true;
}