/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:59:38 by lucca             #+#    #+#             */
/*   Updated: 2026/09/04 18:16:24 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void): type("AAnimal")
{
	std::cout << "[AAnimal] Default Constructor being called.\n";
}

AAnimal::AAnimal(const AAnimal& other): type("AAnimal")
{
	std::cout << "[AAnimal] Constructor being called.\n";
	*this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "[AAnimal] Assignment Operator being called.\n";
	if (this != &other)
	{
		type = other.getType();
	}
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "[AAnimal] Destructor being called.\n";
}

void	AAnimal::makeSound(void)	const
{
	std::cout << "..." << '\n';
}

std::string	AAnimal::getType(void)	const
{
	return (type);
}
