/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:32:54 by lucca             #+#    #+#             */
/*   Updated: 2026/10/12 10:30:45 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <string>

Data::Data(): _name("Default")
{
}

Data::Data(const std::string& name): _name(name)
{
}

Data::Data(const Data& other)
{
	*this = other;
}

Data&	Data::operator=(const Data& other)
{
	if (this != &other)
		_name = other._name;
	return (*this);
}

Data::~Data()
{
}

const std::string&	Data::getName() const
{
	return (_name);
}
