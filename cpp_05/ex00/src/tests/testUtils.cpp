/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 19:55:39 by lucca             #+#    #+#             */
/*   Updated: 2026/09/18 12:19:29 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	printHeader(const std::string& title, int headerType)
{
	if (headerType == 0)
	{
		std::cout << "========================================\n";
		std::cout << title << '\n';
		std::cout << "========================================\n";
	}
	else
	{
		std::cout << "===== [" << title << "]\n";
	}
}

int	test(const std::string& title, int (*testFun)(), int headerType)
{
	printHeader(title, headerType);
	if (testFun() != 0)
	{
		std::cout << "STATUS [" << title << "]: FAILED\n";
		return (-1);
	}
	std::cout << "STATUS [" << title << "]: SUCCESS\n";
	return (0);
}
