/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:48:23 by lucca             #+#    #+#             */
/*   Updated: 2026/09/08 11:51:15 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure(void): AMateria("cure"){}

Cure::Cure(Cure const & other): AMateria(other.type_)
{
	*this = other;
}

Cure&	Cure::operator=(Cure const & other)
{
	return (*this);
}

Cure::~Cure(void){}

AMateria*	Cure::clone(void)	const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std:: cout << "* heals " << target.getName() << "'s wounds *";
}
