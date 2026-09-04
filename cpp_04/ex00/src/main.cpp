/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:57:23 by lucca             #+#    #+#             */
/*   Updated: 2026/09/04 17:23:38 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static int	testSpecialMembers(void)
{
	Animal animal;
	Animal animalCopy(animal);
	Animal assignedAnimal;
	Animal *animalResult = &(assignedAnimal = animal);

	if (animalCopy.getType() != "Animal"
		|| assignedAnimal.getType() != "Animal"
		|| animalResult != &assignedAnimal)
		return (1);
	assignedAnimal = assignedAnimal;
	if (assignedAnimal.getType() != "Animal")
		return (1);

	Dog dog;
	Dog dogCopy(dog);
	Dog assignedDog;
	Dog *dogResult = &(assignedDog = dog);

	if (dogCopy.getType() != "Dog"
		|| assignedDog.getType() != "Dog"
		|| dogResult != &assignedDog)
		return (1);
	assignedDog = assignedDog;
	if (assignedDog.getType() != "Dog")
		return (1);

	Cat cat;
	Cat catCopy(cat);
	Cat assignedCat;
	Cat *catResult = &(assignedCat = cat);

	if (catCopy.getType() != "Cat"
		|| assignedCat.getType() != "Cat"
		|| catResult != &assignedCat)
		return (1);
	assignedCat = assignedCat;
	if (assignedCat.getType() != "Cat")
		return (1);
	return (0);
}

int	main(void)
{
	std::cout	<< "---------------------------------------\n"
				<< "------------ construction  ------------\n"
				<< "---------------------------------------\n";
	Animal staticAnimal = Animal();
	Animal staticSliced = Dog();		// to show how slicing works
	Animal *dynamicDog = new Dog();
	Animal *dynamicCat = new Cat();
	std::cout << '\n';

	std::cout	<< "---------------------------------------\n"
				<< "---------------- types ----------------\n"
				<< "---------------------------------------\n";
	std::cout << "### staticAnimal type: " << staticAnimal.getType() << '\n';
	std::cout << "### staticSliced type: " << staticSliced.getType() << '\n';
	std::cout << "### dynamicDog type:   " << dynamicDog->getType() << '\n';
	std::cout << "### dynamicCat type:   " << dynamicCat->getType() << '\n';
	std::cout << '\n';

	std::cout	<< "---------------------------------------\n"
				<< "--------------- sounds  ---------------\n"
				<< "---------------------------------------\n";
	std::cout << "### staticAnimal sound: ";
	staticAnimal.makeSound();
	std::cout << "### staticSliced sound: ";
	staticSliced.makeSound();
	std::cout << "### dynamicDog sound:   ";
	dynamicDog->makeSound();
	std::cout << "### dynamicCat sound:   ";
	dynamicCat->makeSound();
	std::cout << '\n';

	std::cout	<< "---------------------------------------\n"
				<< "----------- special members -----------\n"
				<< "---------------------------------------\n";
	if (testSpecialMembers() != 0)
	{
		std::cerr << "Special member tests failed.\n";
		delete dynamicDog;
		delete dynamicCat;
		return (1);
	}
	std::cout << "Special member tests passed.\n";

	std::cout	<< "---------------------------------------\n"
				<< "------------- destruction -------------\n"
				<< "---------------------------------------\n";
	std::cout << "### dynamicDog destruction:\n";
	delete dynamicDog;
	std::cout << "### dynamicCat destruction:\n";
	delete dynamicCat;
	std::cout << "### staticAnimal destruction:\n";
}
