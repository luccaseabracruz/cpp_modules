/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:01:47 by lucca             #+#    #+#             */
/*   Updated: 2026/10/14 12:09:48 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int	main()
{
	uintptr_t	nPtr;
	Data		data("Strange Structure");
	Data*		dataPtr;

	nPtr = Serializer::serialize(&data);
	dataPtr = Serializer::deserialize(nPtr);
	if (dataPtr != &data)
	{
		std::cerr << "Error: pointer round-trip failed" << std::endl;
		return (1);
	}
	std::cout << "Original Data address: " << &data << std::endl;
	std::cout << "Deserialized Data address: " << dataPtr << std::endl;
	std::cout << "Pointer round-trip: OK" << std::endl;
	return (0);
}
