/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:54:23 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/15 11:27:34 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (char **arg = argv + 1; *arg != nullptr; arg++)
	{
		for (unsigned char c : std::string(*arg))
		{
			if (c == '\n')
				std::cout << '\n';
			else
				std::cout << (char)toupper(c);
		}
	}
	std::cout << '\n';
	return (0);
}
