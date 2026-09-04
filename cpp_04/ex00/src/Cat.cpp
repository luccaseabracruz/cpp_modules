/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:34:30 by lucca             #+#    #+#             */
/*   Updated: 2026/09/04 10:56:02 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat(void)
{
	std::cout << "[Cat] Default Constructor being called.\n";
	type = "Cat";
}

Cat::Cat(const Cat& other): Animal()
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
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "[Cat] Destructor being called.\n";
}

void	Cat::makeSound(void)
{
	std::cout << "Miaaaaau!\n";
}
