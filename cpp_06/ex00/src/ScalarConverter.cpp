/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 19:26:03 by lucca             #+#    #+#             */
/*   Updated: 2026/10/07 15:37:46 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}
ScalarConverter::~ScalarConverter(){}

static void	validateLiteral(const char* literal)
{
	const	std::string str = std::string(literal);
	size_t	len = str.length();
	bool	hasDot = false;
	bool	hasF = false;
	bool	hasSign = str[0] == '+' || str[0] == '-';
	
	for (size_t i = hasSign; i < len; ++i)
	{
		if (!hasDot && str[i] == '.')
			hasDot = true;
		else if (hasDot && !hasF && str[i] == 'f')
			hasF = true;
		else if ((hasDot && hasF) || !std::isdigit(str[i]))
			throw std::invalid_argument("ScalarCoverter::convert: validateLiteral(): invalid literal: " + str);
	}
	if (hasDot)
	{
		size_t	i = str.find('.');
		const bool	hasDigitBefore = i > 0 && std::isdigit(str[i - 1]);
		const bool	hasDigitAfter = i + 1 < len && std::isdigit(str[i + 1]);
		if (!hasDigitBefore && !hasDigitAfter)
			throw std::invalid_argument("ScalarCoverter::convert: validateLiteral(): invalid float literal: " + str);
	}
}

static double	getDouble(const char* literal)
{
	char*	end = NULL;
	double	res = std::strtod(literal, &end);
	if (end && *end && *end != 'f')
		throw std::invalid_argument("ScalarCoverter::convert: getDouble(): invalid literal: " + std::string(literal));
	return (res);
}

void	ScalarConverter::convert(const char* literal)
{
	double	num;

	if (!literal)
		throw std::invalid_argument("pointer argument is Null");
	if (std::string(literal).length() == 1 && literal[0] && !std::isdigit(static_cast<unsigned char>(literal[0])))
		num = static_cast<double>(literal[0]);
	else
	{
		validateLiteral(literal);
		num = getDouble(literal);
	}
	std::cout << num << std::endl;
}
