/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:17:52 by lucca             #+#    #+#             */
/*   Updated: 2026/09/08 11:46:52 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice(void): AMateria("ice"){}

Ice::Ice(Ice const & other): AMateria(other.type_)
{
	*this = other;
}

Ice&	Ice::operator=(Ice const & other)
{
	return (*this);
}

Ice::~Ice(void){}

AMateria*	Ice::clone(void)	const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std:: cout << "* shoots an ice bolt at " << target.getName() << " *";
}
