/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:34:16 by lucca             #+#    #+#             */
/*   Updated: 2026/09/04 18:16:55 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "[Dog] Default Constructor being called.\n";
	type = "Dog";
}

Dog::Dog(const Dog& other): Animal()
{
	std::cout << "[Dog] Constructor being called.\n";
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] Assignment Operator being called.\n";
	if (this != &other)
	{
		type = other.getType();
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "[Dog] Destructor being called.\n";
}

void	Dog::makeSound(void)	const
{
	std::cout << "Ruf!\n";
}
