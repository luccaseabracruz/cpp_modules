#include <iostream>
#include <new>
#include "Cat.hpp"
#include "tests.hpp"

static int	checkType(const Cat& cat)
{
	if (cat.getType() != "Cat" || cat.getBrainPtr() == NULL)
		return (-1);
	return (0);
}

static int	testConstruction()
{
	printSection("Test Construction");
	Cat	cat;
	if (checkType(cat) != 0)
		return (-1);
	return (0);
}

static int	testCopyConstructor()
{
	printSection("Test Copy Constructor");
	Cat	cat;
	Cat	copy(cat);
	cat.getBrainPtr()->setIdea(0, "mice");
	if (&cat == &copy || cat.getBrainPtr() == copy.getBrainPtr()
		|| copy.getBrainPtr()->getIdea(0) != "")
		return (-1);
	copy.getBrainPtr()->setIdea(0, "nap");
	if (cat.getBrainPtr()->getIdea(0) == copy.getBrainPtr()->getIdea(0))
		return (-1);
	return (0);
}

static int	testAssignmentOperator()
{
	printSection("Test Assignment Operator");
	Cat	cat;
	Cat	copy;
	cat.getBrainPtr()->setIdea(0, "mice");
	Cat	*result = &(copy = cat);
	if (result != &copy || copy.getBrainPtr() == cat.getBrainPtr()
		|| copy.getBrainPtr()->getIdea(0) != "mice")
		return (-1);
	Cat	*self = &copy;
	copy = *self;
	if (copy.getBrainPtr()->getIdea(0) != "mice")
		return (-1);
	return (0);
}

static int	testMakeSound()
{
	printSection("Test Make Sound");
	Animal	*animal = NULL;
	try
	{
		animal = new Cat();
		animal->makeSound();
		if (animal->getType() != "Cat")
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

int	testCat()
{
	printHeader("Test Cat");
	if (
		testConstruction() != 0
		|| testCopyConstructor() != 0
		|| testAssignmentOperator() != 0
		|| testMakeSound() != 0
	)
		return (-1);
	return (0);
}