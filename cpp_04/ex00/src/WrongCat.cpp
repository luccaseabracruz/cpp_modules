/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 18:30:36 by lucca             #+#    #+#             */
/*   Updated: 2026/09/04 18:49:20 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	std::cout << "[WrongCat] Default Constructor being called.\n";
	type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal()
{
	std::cout << "[WrongCat] Constructor being called.\n";
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "[WrongCat] Assignment Operator being called.\n";
	if (this != &other)
	{
		type = other.getType();
	}
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "[WrongCat] Destructor being called.\n";
}

void	WrongCat::makeSound(void)	const
{
	std::cout << "Wrong miau miau" << '\n';
}
