/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 19:26:03 by lucca             #+#    #+#             */
/*   Updated: 2026/10/08 16:58:15 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cerrno>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

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

static void	parseScalarType(ScalarData& dt)
{
	const	std::string str = std::string(dt.literal);
	size_t	len = str.length();

	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		dt.type = CHAR;
		return ;
	}
	else if (str == "nan" || str == "nanf"
			|| str == "inf" || str == "inff" || str == "+inf" || str == "+inff"
			|| str == "-inf" || str == "-inff" )
		dt.type = PSEUDO_LITERAL;
	else
	{
		dt.type = INT;
		for (size_t i = (str[0] == '+' || str[0] == '-'); i < len; ++i)
		{
			if (std::isdigit(str[i]))
				continue ;
			else if (str[i] == '.' && dt.type == INT
				&& ((i > 0 && std::isdigit(str[i - 1])) || (i + 1 < len && std::isdigit(str[i + 1]))))
			{
				dt.type = DOUBLE;
			}
			else if (str[i] == 'f' && dt.type == DOUBLE)
				dt.type = FLOAT;
			else
				throw std::invalid_argument("parseScalarType(): " + str);
		}
	}
}

static void	parseChar(ScalarData& dt)
{
	char	c = dt.literal[0];

	if (c < std::numeric_limits<char>::min() || c > std::numeric_limits<char>::max())
		throw std::range_error("parseChar(): impossible to convert literal into char");
	dt.num = static_cast<double>(c);
}

static void	printChar(const double& num)
{
	std::cout << "char: ";
	if (num != num || num < 0 || num > 127)
		std::cout << "impossible";
	else if (num < 32 || num == 127)
		std::cout << "Non displayable";
	else
		std::cout << '\'' << static_cast<char>(num) << '\'';
	std::cout << std::endl;
}

static void	parseInt(ScalarData& dt)
{
	char*	end = NULL;
	long	longValue = std::strtol(dt.literal, &end, 10);
	int		intValue;

	if (end && *end)
		throw std::invalid_argument("parseInt(): " + std::string(dt.literal));
	if (longValue < std::numeric_limits<int>::min() || longValue > std::numeric_limits<int>::max())
		throw std::range_error("parseInt(): impossible to convert string into int");
	intValue = static_cast<int>(longValue);
	dt.num = static_cast<double>(intValue);
}

static void	printInt(const double& num)
{
	std::cout << "int: ";
	if (num != num
		|| num < static_cast<double>(std::numeric_limits<int>::min())
		|| num > static_cast<double>(std::numeric_limits<int>::max()))
	{
		std::cout << "impossible";
	}
	else
		std::cout << static_cast<int>(num);
	std::cout << std::endl;
}

static void	parseFloat(ScalarData& dt)
{
	char*	end = NULL;
	double	doubleValue = std::strtod(dt.literal, &end);
	float	floatValue;

	if (end && *end && *end != 'f')
		throw std::invalid_argument("parseFloat(): invalid literal: " + std::string(dt.literal));
	if (doubleValue < -std::numeric_limits<float>::max() || doubleValue > std::numeric_limits<float>::max())
		throw std::range_error("parseFloat(): impossible to convert literal into float");
	floatValue = static_cast<float>(doubleValue);
	dt.num = static_cast<double>(floatValue);
}

static void	printFloat(const double& num)
{
	std::cout << "float: ";
	if (num < -std::numeric_limits<float>::max() || num > std::numeric_limits<float>::max())
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(2) << static_cast<float>(num) << 'f';
	std::cout << std::endl;
}

static void	parseDouble(ScalarData& dt)
{
	char*	end = NULL;
	errno = 0;
	double	doubleValue = std::strtod(dt.literal, &end);

	if (end && *end && *end != 'f')
		throw std::invalid_argument("printDouble(): " + std::string(dt.literal));
	if (errno == ERANGE)
		throw std::range_error("parseFloat(): impossible to convert literal into double");
	dt.num = doubleValue;
}

static void	printDouble(const double& num)
{
	std::cout << "double: ";
	if (num < -std::numeric_limits<double>::max() || num > std::numeric_limits<double>::max())
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(2) << static_cast<double>(num);
	std::cout << std::endl;
}

static void	parsePseudoLiteral(ScalarData& dt)
{
	const std::string str(dt.literal);

	if (str == "nan" || str == "nanf")
		dt.num = std::numeric_limits<double>::quiet_NaN();
	else if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff")
		dt.num = std::numeric_limits<double>::infinity();
	else if (str == "-inf" || str == "-inff")
		dt.num = -std::numeric_limits<double>::infinity();
}

void	ScalarConverter::convert(const char* literal)
{
	ScalarData	dt = {literal, {"char: ", "int: ", "float: ", "double: "}, INT, 0};
	void (*parseFunctions[5])(ScalarData&) = {
		parseChar, parseInt, parseFloat, parseDouble, parsePseudoLiteral
	};
	void (*printFunctions[4])(const double&) = {
		printChar, printInt, printFloat, printDouble,
	};

	if (!literal)
		throw std::invalid_argument("ScalarConverter::convert: pointer argument passed as parameter has Null value");
	if (!*literal)
		throw std::invalid_argument("ScalarConverter::convert: argument passed is empty");
	parseScalarType(dt);
	parseFunctions[dt.type](dt);
	for (size_t i = 0; i < sizeof(printFunctions)/sizeof(printFunctions[0]); ++i)
		printFunctions[i](dt.num);
}
