/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:35:00 by lucca             #+#    #+#             */
/*   Updated: 2026/08/25 10:47:46 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

// int	main( void )
// {
// 	Fixed	a(7.01f);
// 	std::cout << "a is " << a << std::endl;
// 	Fixed	b(a--);
// 	std::cout << "b is a-- = " << b << std::endl;
// 	std::cout << "is a == b? " << (a == b) << std::endl;
// 	std::cout << "now, a is " << a << std::endl;
// 	Fixed	c(--a);
// 	std::cout << "c is --a = " << c << std::endl;
// 	std::cout << "now, a is " << a << std::endl;

// 	return 0;
// }
