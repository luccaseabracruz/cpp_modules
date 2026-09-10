/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:02:11 by lucca             #+#    #+#             */
/*   Updated: 2026/09/10 10:59:02 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

static void	printHeader(const std::string& title)
{
	std::cout << "========================================\n";
	std::cout << title << '\n';
	std::cout << "========================================\n";
}

static void sugestedTests(void)
{
	printHeader("Subject Test");
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

static int	testMateriaSource(void)
{
	printHeader("Materia Source Limits");
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

static int	testCharacterBounds(void)
{
	printHeader("Character Bounds");
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

static int	testCharacterInventory(void)
{
	printHeader("Character Inventory Limits");
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

static int	testLimits(void)
{
	if (testMateriaSource() != 0)
		return (-1);
	if (testCharacterBounds() != 0)
		return (-1);
	if (testCharacterInventory() != 0)
		return (-1);
	return (0);
}

int main()
{
	sugestedTests();
	if (testLimits() != 0)
	{
		std::cout << ">>> Test Limits: FAILURE... :(\n";
		return (1);
	}
	std::cout << ">>> Test Limits: SUCESS!!! :)\n";
	return (0);
}
