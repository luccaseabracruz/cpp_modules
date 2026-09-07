/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:34:16 by lucca             #+#    #+#             */
/*   Updated: 2026/09/07 14:43:19 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void): brain(new Brain())
{
	std::cout << "[Dog] Default Constructor being called.\n";
	type = "Dog";
}

Dog::Dog(const Dog& other)
	: Animal(), brain(new Brain())
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
		*brain = *other.brain;
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "[Dog] Destructor being called.\n";
	delete brain;
}

void	Dog::makeSound(void)	const
{
	std::cout << "Ruf!\n";
}

Brain	*Dog::getBrainPtr(void)	const
{
	return (brain);
}
