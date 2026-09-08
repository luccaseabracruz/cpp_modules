/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 00:03:55 by lucca             #+#    #+#             */
/*   Updated: 2026/09/08 11:33:41 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void): type_("")
{
	// std::cout << "[AMateria] default constructor called.\n";
}

AMateria::AMateria(std::string const & type): type_(type)
{
	// std::cout << "[AMateria] constructor called.\n";
}

AMateria::AMateria(AMateria const & other): type_(other.type_)
{
	// std::cout << "[AMateria] copy constructor called.\n";
	*this = other;
}

AMateria& AMateria::operator=(AMateria const & other)
{
	// std::cout << "[AMateria] copy constructor called.\n";
	return (*this);
}

AMateria::~AMateria(void)
{
	// std::cout << "[AMateria] destructor called.\n";
}

std::string const & AMateria::getType(void)	const
{
	return type_;
}

// void	AMateria::use(ICharacter& target)
// {
	
// }