/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 00:03:55 by lucca             #+#    #+#             */
/*   Updated: 2026/09/10 13:05:02 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void): type_(""){}

AMateria::AMateria(std::string const & type): type_(type){}

AMateria::AMateria(AMateria const & other): type_(other.type_)
{
	*this = other;
}

AMateria& AMateria::operator=(AMateria const & other)
{
	(void)other;
	return (*this);
}

AMateria::~AMateria(void){}

std::string const & AMateria::getType(void)	const
{
	return type_;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}
