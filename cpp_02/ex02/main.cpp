/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:35:00 by lucca             #+#    #+#             */
/*   Updated: 2026/08/24 20:46:38 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

// int	main( void )
// {
// 	Fixed		b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	Fixed const	a;

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

int	main( void )
{
	Fixed	a(7.01f);
	Fixed	b(7.01f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "a == b? " << (a == b) << std::endl;
	std::cout << "a > b? " << (a > b) << std::endl;
	std::cout << "a >= b? " << (a >= b) << std::endl;
	std::cout << "a < b? " << (a < b) << std::endl;
	std::cout << "a <= b? " << (a <= b) << std::endl;

	return 0;
}
