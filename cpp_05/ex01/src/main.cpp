/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 19:24:07 by lucca             #+#    #+#             */
/*   Updated: 2026/09/29 12:23:15 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "tests.hpp"

int	main()
{
	int	status = 0;

	if (testBureaucrat() != 0)
	{
		std::cout << "STATUS [Test Bureaucrat]: FAILED\n";
		status = 1;
	}
	else
		std::cout << "STATUS [Test Bureaucrat]: SUCCESS\n";
	if (testForm() != 0)
	{
		std::cout << "STATUS [Test Form]: FAILED\n";
		status = 1;
	}
	else
		std::cout << "STATUS [Test Form]: SUCCESS\n";
	return (status);
}
