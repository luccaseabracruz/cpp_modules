/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:59:38 by lucca             #+#    #+#             */
/*   Updated: 2026/09/04 18:16:24 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("Animal")
{
	std::cout << "[Animal] Default Constructor being called.\n";
}

Animal::Animal(const Animal& other): type("Animal")
{
	std::cout << "[Animal] Constructor being called.\n";
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "[Animal] Assignment Operator being called.\n";
	if (this != &other)
	{
		type = other.getType();
	}
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "[Animal] Destructor being called.\n";
}

void	Animal::makeSound(void)	const
{
	std::cout << "..." << '\n';
}

std::string	Animal::getType(void)	const
{
	return (type);
}
