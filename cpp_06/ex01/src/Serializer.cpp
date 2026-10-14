/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:22:38 by lucca             #+#    #+#             */
/*   Updated: 2026/10/12 10:36:33 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <stdint.h>

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& other)
{
	*this = other;
}

Serializer&	Serializer::operator=(const Serializer& other)
{
	(void) other;
	return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	res;

	res = reinterpret_cast<uintptr_t>(ptr);
	return (res);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	Data	*res;

	res = reinterpret_cast<Data*>(raw);
	return (res);
}
