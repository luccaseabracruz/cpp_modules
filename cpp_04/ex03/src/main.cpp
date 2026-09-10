/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:02:11 by lucca             #+#    #+#             */
/*   Updated: 2026/09/10 13:40:50 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

static void	printHeader(const std::string& title, int headerType)
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

static void runSubjectTest(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	std::cout << '\n';
}

static int	testMateriaSourceCapacity(void)
{
	IMateriaSource	*src = new MateriaSource;

	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
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

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	tmpIce = src->createMateria("ice");
	tmpCure = src->createMateria("cure");
	tony->equip(tmpIce);
	tony->equip(tmpCure);
	tony->use(0, *rodney);
	tony->use(1, *rodney);
	tony->equip(tmpCure);
	tony->equip(tmpCure);
	tony->equip(tmpIce);
	tony->equip(tmpIce);
	tony->use(4, *rodney);
	tony->unequip(4);
	tony->use(4, *rodney);
	delete src;
	delete tony;
	delete rodney;
	return (0);
}

static int	testDeepCopy(void)
{
	IMateriaSource	*src;
	IMateriaSource	*copy;
	AMateria		*tmp;
	Character		*tony;
	Character		*roodney;
	int				status = 0;

	src = new MateriaSource();
	copy = new MateriaSource();
	*copy = *src;
	src->learnMateria(new Ice());
	copy->learnMateria(new Cure());
	tmp = src->createMateria("cure");
	if (tmp)
	{
		std::cout << "Error: testDeepCopy(): shallow copy detected: MateriaSource class.\n";
		status = -1;
	}
	tony = new	Character("Tony");
	roodney = new	Character("Roodney");
	tmp = src->createMateria("ice");
	tmp->use(*roodney);
	delete	tmp;
	delete	src;
	delete	copy;
	delete	tony;
	delete	roodney;
	return (status);
}

static int	runMyTests(void)
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

int main()
{
	printHeader("Subject Test", 0);
	runSubjectTest();
	printHeader("My Tests", 0);
	if (runMyTests() != 0)
	{
		std::cout << ">>>>> My Tests: FAILURE... :(\n";
		return (1);
	}
	std::cout << ">>>>> My Tests: SUCESS!!! :)\n";
	return (0);
}
