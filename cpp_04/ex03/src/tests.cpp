/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:33:53 by lucca             #+#    #+#             */
/*   Updated: 2026/09/10 15:16:11 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	testDeepCopy(void);

void	printHeader(const std::string& title, int headerType)
{
	if (headerType == 0)
	{
		std::cout << "========================================\n";
		std::cout << title << '\n';
		std::cout << "========================================\n";
	}
	else
	{
		std::cout << "===== [" << title << "]\n";
	}
}

static int	testMateriaSourceCapacity(void)
{
	IMateriaSource	*src = new MateriaSource;
	AMateria	*overflowIce = new Ice();
	AMateria	*overflowCure = new Cure();

	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(overflowIce);
	src->learnMateria(overflowCure);
	delete overflowIce;
	delete overflowCure;
	if (src->createMateria("whatever") != NULL)
	{
		std::cout << "Error: unknown materia type should return NULL.\n";
		delete src;
		return (-1);
	}
	delete src;
	return (0);
}

static int	testCharacterInvalidIndexes(void)
{
	Character	*tony = new Character("Tony");
	Character	*rodney = new Character("Rodney");

	tony->unequip(-1);
	tony->unequip(0);
	tony->use(3, *rodney);
	tony->use(4, *rodney);
	tony->use(213321654, *rodney);
	tony->use(-213321654, *rodney);
	delete tony;
	delete rodney;
	return (0);
}

static int	testCharacterInventoryCapacity(void)
{
	IMateriaSource	*src = new MateriaSource;
	Character	*tony = new Character("Tony");
	Character	*rodney = new Character("Rodney");
	AMateria	*tmpIce;
	AMateria	*tmpCure;
	AMateria	*overflowCure;
	AMateria	*overflowIce;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	tmpIce = src->createMateria("ice");
	tmpCure = src->createMateria("cure");
	tony->equip(tmpIce);
	tony->equip(tmpCure);
	tony->use(0, *rodney);
	tony->use(1, *rodney);
	tony->equip(new Cure());
	tony->equip(new Cure());
	overflowCure = new Cure();
	overflowIce = new Ice();
	tony->equip(overflowCure);
	tony->equip(overflowIce);
	delete overflowCure;
	delete overflowIce;
	tony->use(4, *rodney);
	tony->unequip(4);
	tony->use(4, *rodney);
	delete src;
	delete tony;
	delete rodney;
	return (0);
}

int	runMyTests(void)
{
	printHeader("Materia Source Capacity", 1);;
	if (testMateriaSourceCapacity() != 0)
	{
		std::cout << ">>> Test Materia Source Capacity ----> FAILED";
		return (-1);
	}
	printHeader("Character Invalid Indexes", 1);
	if (testCharacterInvalidIndexes() != 0)
	{
		std::cout << ">>> Test Character Invalid Indexes ----> FAILED";
		return (-1);
	}
	printHeader("Character Inventory Capacity", 1);
	if (testCharacterInventoryCapacity() != 0)
	{
		std::cout << ">>> Test Character Inventory Capacity ----> FAILED";
		return (-1);
	}
	printHeader("Deep Copy", 1);
	if (testDeepCopy() != 0)
	{
		std::cout << ">>> Test Deep Copy ----> FAILED";
		return (-1);
	}
	return (0);
}
