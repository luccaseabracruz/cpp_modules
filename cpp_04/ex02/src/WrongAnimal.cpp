/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 18:14:25 by lucca             #+#    #+#             */
/*   Updated: 2026/09/04 18:34:10 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("Wrong Animal")
{
	std::cout << "[WrongAnimal] Default Constructor being called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type("Wrong Animal")
{
	std::cout << "[WrongAnimal] Constructor being called.\n";
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "[WrongAnimal] Assignment Operator being called.\n";
	if (this != &other)
	{
		type = other.getType();
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "[WrongAnimal] Destructor being called.\n";
}

void	WrongAnimal::makeSound(void)	const
{
	std::cout << "Wrong ..." << '\n';
}

std::string	WrongAnimal::getType(void)	const
{
	return (type);
}
