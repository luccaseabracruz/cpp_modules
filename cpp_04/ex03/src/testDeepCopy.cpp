/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testDeepCopy.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:42:32 by lucca             #+#    #+#             */
/*   Updated: 2026/09/11 11:19:46 by lucca            ###   ########.fr       */
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
	MateriaSource	*src = new MateriaSource;
	MateriaSource	*copy = new MateriaSource;
	AMateria		*tmp;
	int				status = 0;
	AMateria		*ice = new Ice();
	AMateria		*cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(cure);
	*copy = *src;
	tmp = copy->createMateria("ice");
	if (tmp == NULL)
	{
		std::cout << "Error: MateriaSource assignment lost Ice.\n";
		status = -1;
	}
	delete tmp;
	delete src;
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
	MateriaSource	*src = new MateriaSource;
	MateriaSource	*copy;
	AMateria		*tmp;
	int				status = 0;
	AMateria	*ice = new Ice();
	AMateria	*cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(cure);
	delete ice;
	delete cure;
	copy = new MateriaSource(*src);
	tmp = copy->createMateria("ice");
	if (tmp == NULL)
		status = -1;
	delete tmp;
	tmp = copy->createMateria("cure");
	if (tmp == NULL)
		status = -1;
	delete tmp;
	delete src;
	delete copy;
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
