/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:57:23 by lucca             #+#    #+#             */
/*   Updated: 2026/09/04 18:57:47 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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

static int	testWrongAnimal(void)
{
	WrongAnimal	*wrong;
	WrongAnimal	*wrongCat;

	wrong = new WrongAnimal();
	if (wrong == NULL)
	{
		std::cerr << "Error: allocation failed.\n";
		return (-1);
	}
	wrongCat = new WrongCat();
	if (wrongCat == NULL)
	{
		std::cerr << "Error: allocation failed.\n";
		delete wrong;
		return (-1);
	}
	std::cout 	<< "[Wrong Animal]:\n    type: " << wrong->getType()
				<< "\n    sound: ";
	wrong->makeSound();
	std::cout 	<< "[Wrong Cat]:\n    type: " << wrongCat->getType()
				<< "\n    sound: ";
	wrongCat->makeSound();
	std::cout << "OBS: sounds must be equal. Testing failing dynamic polymorphism\n";
	delete wrong;
	delete wrongCat;
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
	if (dynamicDog == NULL)
	{
		std::cerr << "Error: allocation failed.\n";
		return (1);
	}
	Animal *dynamicCat = new Cat();
	if (dynamicCat == NULL)
	{
		std::cerr << "Error: allocation failed.\n";
		delete dynamicDog;
		return (1);
	}
	std::cout << '\n';

	std::cout	<< "---------------------------------------\n"
				<< "---------------- type  ----------------\n"
				<< "---------------------------------------\n";
	std::cout << "### staticAnimal type: " << staticAnimal.getType() << '\n';
	std::cout << "### staticSliced type: " << staticSliced.getType() << '\n';
	std::cout << "### dynamicDog type:   " << dynamicDog->getType() << '\n';
	std::cout << "### dynamicCat type:   " << dynamicCat->getType() << '\n';
	std::cout << '\n';

	std::cout	<< "---------------------------------------\n"
				<< "--------------- Sounds  ---------------\n"
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
				<< "----------- Special Members -----------\n"
				<< "---------------------------------------\n";
	if (testSpecialMembers() != 0)
	{
		std::cerr << "Special member tests failed.\n";
		delete dynamicDog;
		delete dynamicCat;
		return (1);
	}
	std::cout << "Special member tests passed.\n";
	std::cout << '\n';

	std::cout	<< "---------------------------------------\n"
				<< "------------ Wrong Animal  ------------\n"
				<< "---------------------------------------\n";
	if (testWrongAnimal() != 0)
	{
		std::cerr << "Wrong Animal tests failed.\n";
		delete dynamicDog;
		delete dynamicCat;
		return (1);
	}
	std::cout << "Wrong Animal tests passed.\n";
	std::cout << '\n';

	std::cout	<< "---------------------------------------\n"
				<< "------------- destruction -------------\n"
				<< "---------------------------------------\n";
	std::cout << "### dynamicDog destruction:\n";
	delete dynamicDog;
	std::cout << "### dynamicCat destruction:\n";
	delete dynamicCat;
	std::cout << "### staticAnimal destruction:\n";
}
