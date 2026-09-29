/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 19:55:39 by lucca             #+#    #+#             */
/*   Updated: 2026/09/29 16:28:47 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	printHeader(const std::string& title, int headerType)
{
	if (headerType == 0)
	{
		std::cout << "========================================\n";
		std::cout << "===" << title << '\n';
		std::cout << "========================================\n";
	}
	else
	{
		std::cout << "------------------------------\n";
		std::cout << "---" << title << '\n';
		std::cout << "------------------------------\n";
	}
}

int	runTest(int (*f)(), const std::string& title)
{
	std::string	msg = "STATUS [" + title + "]: ";

	if (f() != 0)
	{
		std::cout << msg << "FAILED\n";
		return (-1);
	}
	std::cout << msg << "SUCCESS\n";
	return (0);
}
