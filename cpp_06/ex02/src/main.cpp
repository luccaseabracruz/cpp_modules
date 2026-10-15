/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:18:32 by lucca             #+#    #+#             */
/*   Updated: 2026/10/15 16:49:11 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int	main()
{
	Base* ptr;
	A	a;
	B	b;
	C	c;

	std::cout << ">>> Test generate\n";
	ptr = generate();
	std::cout << ">>> Identify Pointer\n";
	identify(ptr);
	std::cout << ">>> Identify Reference\n";
	identify(a);
	identify(b);
	identify(c);
	delete ptr;
	return (0);
}
