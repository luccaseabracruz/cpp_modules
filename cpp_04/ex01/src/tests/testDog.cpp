#include <iostream>
#include <new>
#include "Dog.hpp"
#include "tests.hpp"

static int	checkType(const Dog& dog)
{
	if (dog.getType() != "Dog" || dog.getBrainPtr() == NULL)
		return (-1);
	return (0);
}

static int	testConstruction()
{
	printSection("Test Construction");
	Dog	dog;
	if (checkType(dog) != 0)
		return (-1);
	return (0);
}

static int	testCopyConstructor()
{
	printSection("Test Copy Constructor");
	Dog	dog;
	Dog	copy(dog);
	dog.getBrainPtr()->setIdea(0, "bones");
	if (&dog == &copy || dog.getBrainPtr() == copy.getBrainPtr()
		|| copy.getBrainPtr()->getIdea(0) != "")
		return (-1);
	copy.getBrainPtr()->setIdea(0, "play");
	if (dog.getBrainPtr()->getIdea(0) == copy.getBrainPtr()->getIdea(0))
		return (-1);
	return (0);
}

static int	testAssignmentOperator()
{
	printSection("Test Assignment Operator");
	Dog	dog;
	Dog	copy;
	dog.getBrainPtr()->setIdea(0, "bones");
	Dog	*result = &(copy = dog);
	if (result != &copy || copy.getBrainPtr() == dog.getBrainPtr()
		|| copy.getBrainPtr()->getIdea(0) != "bones")
		return (-1);
	Dog	*self = &copy;
	copy = *self;
	if (copy.getBrainPtr()->getIdea(0) != "bones")
		return (-1);
	return (0);
}

static int	testMakeSound()
{
	printSection("Test Make Sound");
	Animal	*animal = NULL;
	try
	{
		animal = new Dog();
		animal->makeSound();
		if (animal->getType() != "Dog")
		{
			delete animal;
			return (-1);
		}
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
		return (-1);
	}
	delete animal;
	return (0);
}

int	testDog()
{
	printHeader("Test Dog");
	if (
		testConstruction() != 0
		|| testCopyConstructor() != 0
		|| testAssignmentOperator() != 0
		|| testMakeSound() != 0
	)
		return (-1);
	return (0);
}