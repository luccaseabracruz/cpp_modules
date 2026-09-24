/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subjectTests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 14:55:07 by lseabra-          #+#    #+#             */
/*   Updated: 2026/09/24 15:06:24 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "tests.hpp"

static int	subjectMainTest()
{
	printSection("Subject Main Test");
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	return (0);
}

static int	subjectWrongTest()
{
	printSection("Subject Wrong Test");
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << "Type: " << i->getType() << " " << std::endl << "Sound: ";
	i->makeSound(); //will output the wrong animal sound rather than cat sound!
	std::cout << "Type: " << meta->getType() << " " << std::endl << "Sound: ";
	meta->makeSound();
	delete meta;
	delete i;
	return (0);
}

int	subjectTests()
{
	subjectMainTest();
	subjectWrongTest();
	return (0);
}
