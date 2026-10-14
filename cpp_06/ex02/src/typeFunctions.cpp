/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeFunctions.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:15:50 by lucca             #+#    #+#             */
/*   Updated: 2026/10/14 13:03:03 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>


Base* generate()
{
	int	diceValue;

	std::srand(time(0));
	diceValue = std::rand() % 6;
	std::cout << "Dice value: " << diceValue << std::endl;
	if (diceValue < 2)
		return (new A);
	else if (diceValue < 4)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	}
	catch (std::exception&){}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	}
	catch (std::exception&){}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	}
	catch (std::exception&){}
}
