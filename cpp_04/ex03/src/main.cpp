/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:02:11 by lucca             #+#    #+#             */
/*   Updated: 2026/09/23 16:52:11 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	main(int argc, char *argv[])
{
	int	status = 0;

	if (argc > 1 && std::string(argv[1]) == "-a")
	{
		if (test(testDeepCopy, "Test Deep Copy") != 0)
			status = 1;
		if (test(runMyTests, "My Tests") != 0)
			status = 1;
	}
	if (test(subjectTest, "Subject Test") != 0)
		status = 1;
	return (status);
}
