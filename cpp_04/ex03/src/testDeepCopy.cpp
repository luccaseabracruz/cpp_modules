/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testDeepCopy.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:42:32 by lucca             #+#    #+#             */
/*   Updated: 2026/09/10 15:00:33 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

static int	testMateriaSourceCopy(void)
{
	MateriaSource	*source = new MateriaSource;
	MateriaSource	*copy = new MateriaSource;
	AMateria		*tmp;
	int				status = 0;

	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	*copy = *source;
	tmp = copy->createMateria("ice");
	if (tmp == NULL)
	{
		std::cout << "Error: MateriaSource assignment lost Ice.\n";
		status = -1;
	}
	delete tmp;
	delete source;
	tmp = copy->createMateria("cure");
	if (tmp == NULL)
	{
		std::cout << "Error: MateriaSource copy is not independent.\n";
		status = -1;
	}
	delete tmp;
	delete copy;
	return (status);
}

static int	testMateriaSourceCopyConstructor(void)
{
	MateriaSource	*source = new MateriaSource;
	AMateria		*tmp;
	int				status = 0;

	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	{
		MateriaSource copy(*source);
		tmp = copy.createMateria("ice");
		if (tmp == NULL)
			status = -1;
		delete tmp;
		tmp = copy.createMateria("cure");
		if (tmp == NULL)
			status = -1;
		delete tmp;
	}
	delete source;
	return (status);
}

static int	testCharacterCopy(void)
{
	Character	*tony = new Character("Tony");
	Character	*roodney = new Character("Roodney");
	Character	*copy;
	Character	*target = new Character("Target");
	int			status = 0;

	tony->equip(new Ice());
	tony->equip(new Cure());
	*roodney = *tony;
	if (roodney->getName() != tony->getName())
		status = -1;
	if (tony->getName() != "Tony")
		status = -1;
	tony->use(0, *target);
	tony->use(1, *target);
	copy = new Character(*tony);
	if (copy->getName() != tony->getName())
		status = -1;
	delete tony;
	copy->use(0, *target);
	copy->use(1, *target);
	delete copy;
	delete roodney;
	delete target;
	return (status);
}

int	testDeepCopy(void)
{
	int	status = 0;

	if (testMateriaSourceCopy() != 0)
		status = -1;
	if (testMateriaSourceCopyConstructor() != 0)
		status = -1;
	if (testCharacterCopy() != 0)
		status = -1;
	return (status);
}
