/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runMyTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:33:53 by lucca             #+#    #+#             */
/*   Updated: 2026/09/23 16:52:45 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "tests.hpp"

static int	testMateriaSourceCapacity(void)
{
	IMateriaSource	*src = new MateriaSource;
	AMateria		*nullTest;
	AMateria		*overflowIce = new Ice();
	AMateria		*overflowCure = new Cure();
	AMateria		*ice = new Ice();
	AMateria		*cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(ice);
	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(overflowIce);
	src->learnMateria(overflowCure);
	delete ice;
	delete cure;
	delete overflowIce;
	delete overflowCure;

	nullTest = src->createMateria("whatever");
	if (nullTest != NULL)
	{
		std::cout << "Error: unknown materia type should return NULL.\n";
		delete nullTest;
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
	AMateria	*tmpIce = new Ice();
	AMateria	*tmpCure = new Cure();
	AMateria	*overflowCure;
	AMateria	*overflowIce;

	src->learnMateria(tmpIce);
	src->learnMateria(tmpCure);
	delete tmpIce;
	delete tmpCure;
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
	printHeader("Materia Source Capacity");
	if (testMateriaSourceCapacity() != 0)
		return (-1);
	printSection("Character Invalid Indexes");
	if (testCharacterInvalidIndexes() != 0)
		return (-1);
	printSection("Character Inventory Capacity");
	if (testCharacterInventoryCapacity() != 0)
		return (-1);
	printSection("Deep Copy");
	return (0);
}
