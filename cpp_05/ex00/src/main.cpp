/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 19:24:07 by lucca             #+#    #+#             */
/*   Updated: 2026/09/18 14:02:48 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "tests.hpp"

int	main()
{
	if (testBureaucrat() != 0)
	{
		std::cout << "STATUS [Test Bureaucrat]: FAILED\n";
		return (1);
	}
	std::cout << "STATUS [Test Bureaucrat]: SUCCESS\n";
	return (0);
}
