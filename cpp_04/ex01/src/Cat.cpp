/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:34:30 by lucca             #+#    #+#             */
/*   Updated: 2026/09/07 14:25:18 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Cat::Cat(void): brain(new Brain())
{
	std::cout << "[Cat] Default Constructor being called.\n";
	type = "Cat";
}

Cat::Cat(const Cat& other): Animal(), brain(new Brain(*other.brain))
{
	std::cout << "[Cat] Constructor being called.\n";
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "[Cat] Assignment Operator being called.\n";
	if (this != &other)
	{
		type = other.getType();
		*brain = *other.brain;
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "[Cat] Destructor being called.\n";
	delete brain;
}

void	Cat::makeSound(void)	const
{
	std::cout << "Miaaaaau!\n";
}

Brain	*Cat::getBrainPtr(void)	const
{
	return brain;
}
