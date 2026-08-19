/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:33:28 by lseabra-          #+#    #+#             */
/*   Updated: 2026/08/19 18:23:54 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

static void	test(const std::string& dynamicName, const std::string& staticName)
{
	std::cout << "======================= Test ex01 =======================\n";
	std::cout << ">>> Testing newZombie(\"" + dynamicName + "\")\n";
	Zombie *mj = newZombie(dynamicName);
	if (!mj)
		return ;
	(*mj).announce();
	std::cout << ">>> Testing randomChump(\"" + staticName + "\")\n";
	randomChump(staticName);
	std::cout << ">>> Ending randomChump(\"" + staticName + "\")\n";
	delete mj;
	std::cout << "==================== ending Test ex01 ====================\n";
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		test("Michael Jackson", "Bill Murray");
	else if (argc == 2)
		test(argv[1], "Bill Murray");
	else if (argc >= 3)
		test(argv[1], argv[2]);
	return (0);
};
