/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runSubjectTest.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:38:58 by lucca             #+#    #+#             */
/*   Updated: 2026/09/23 16:53:16 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "tests.hpp"

int	subjectTest(void)
{
	printHeader("Subject Test");
	IMateriaSource	*src = new MateriaSource();
	AMateria		*ice = new Ice();
	AMateria		*cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(cure);
	delete ice;
	delete cure;

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
	return (0);
}
