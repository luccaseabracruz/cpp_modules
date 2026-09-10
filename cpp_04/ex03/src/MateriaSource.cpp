/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:38:21 by lucca             #+#    #+#             */
/*   Updated: 2026/09/10 13:25:07 by lucca            ###   ########.fr       */
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
	for (int i = 0; i < KNOWN_MATERIAS_LEN; i++)
		knownMaterias_[i] = NULL;
	*this = other;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & other)
{
	if (this != &other)
	{
		for (int i = 0; i < KNOWN_MATERIAS_LEN; i++)
		{
			if (knownMaterias_[i] != NULL)
			{
				delete knownMaterias_[i];
				knownMaterias_[i] = NULL;
			}
			if (other.knownMaterias_[i] != NULL)
				knownMaterias_[i] = other.knownMaterias_[i]->clone();
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
			for (int j = i + 1; j < KNOWN_MATERIAS_LEN; j++)
			{
				if (knownMaterias_[j] && knownMaterias_[j] == knownMaterias_[i])
					knownMaterias_[j] = NULL;
			}
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
			return ;
		}
	}
	delete materia;
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
