/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:31:24 by lucca             #+#    #+#             */
/*   Updated: 2026/08/26 14:58:51 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	std::cout << std::boolalpha;

	std::cout << "A(" << a.getX().toInt() << ", " << a.getY().toInt() << ")" << '\n';
	std::cout << "B(" << b.getX().toInt() << ", " << b.getY().toInt() << ")" << '\n';
	std::cout << "C(" << c.getX().toInt() << ", " << c.getY().toInt() << ")" << '\n';

	// Inside
	Point p1(2, 2);
	std::cout << "Inside (2, 2): " << bsp(a, b, c, p1) << std::endl;

	// Outside
	Point p2(8, 8);
	std::cout << "Outside (8, 8): " << bsp(a, b, c, p2) << std::endl;

	// On AB
	Point p3(5, 0);
	std::cout << "On AB (5, 0): " << bsp(a, b, c, p3) << std::endl;

	// On AC
	Point p4(0, 5);
	std::cout << "On AC (0, 5): " << bsp(a, b, c, p4) << std::endl;

	// On BC
	Point p5(5, 5);
	std::cout << "On BC (5, 5): " << bsp(a, b, c, p5) << std::endl;

	// Vertex
	std::cout << "On vertex A (0, 0): " << bsp(a, b, c, a) << std::endl;

	return 0;
}
