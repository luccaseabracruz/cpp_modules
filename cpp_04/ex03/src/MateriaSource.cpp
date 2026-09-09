/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:38:21 by lucca             #+#    #+#             */
/*   Updated: 2026/09/09 11:31:41 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < KNOWN_MATERIAS_LEN; i++)
		knownMaterias_[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
	*this = other;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & other)
{
	if (this != &other)
	{
		for (int i = 0; i < KNOWN_MATERIAS_LEN; i++)
		{
			if (other.knownMaterias_[i] != NULL)
			{
				std::string const & type = other.knownMaterias_[i]->getType();
				AMateria	*newMateria = other.createMateria(type);
				this->learnMateria(newMateria);
				delete newMateria;
			}
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < KNOWN_MATERIAS_LEN; i++)
	{
		if (knownMaterias_[i] != NULL)
		{
			delete knownMaterias_[i];
			knownMaterias_[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < KNOWN_MATERIAS_LEN; i++)
	{
		if (knownMaterias_[i] == NULL)
		{
			knownMaterias_[i] = materia;
			break ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const & type) const
{
	for (int i = 0; i < KNOWN_MATERIAS_LEN; i++)
	{
		if (knownMaterias_[i] != NULL && knownMaterias_[i]->getType() == type)
			return (knownMaterias_[i]->clone());
	}
	return (NULL);
}
