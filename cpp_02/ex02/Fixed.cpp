/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:34:41 by lucca             #+#    #+#             */
/*   Updated: 2026/08/24 20:13:57 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::fractBitsN_ = 8;

float Fixed::toFloat(void) const
{
	return (static_cast<float>(rawBits_) / (1 << fractBitsN_));
}

int Fixed::toInt(void) const
{
	return (rawBits_ >> fractBitsN_);
}

Fixed::Fixed(void): rawBits_(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int iValue)
{
	std::cout << "Int constructor called\n";
	rawBits_ = iValue << fractBitsN_;
}

Fixed::Fixed(const float fValue)
{
	std::cout << "Float constructor called\n";
	rawBits_ = static_cast<int>(roundf(fValue * (1 << fractBitsN_)));
}


Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	//option one
	*this = other;
	//option two
	// this->rawBits_ = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	this->rawBits_ = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed Fixed::operator+(const Fixed& other)
{
	Fixed	res;

	res.setRawBits(this->rawBits_ + other.getRawBits());
	return (res);
}

Fixed Fixed::operator-(const Fixed& other)
{
	Fixed	res;

	res.setRawBits(this->rawBits_ - other.getRawBits());
	return (res);
}

Fixed Fixed::operator*(const Fixed& other)
{
	Fixed	res(this->toFloat() * other.toFloat());
	return (res);
}

Fixed Fixed::operator/(const Fixed& other)
{
	Fixed	res(this->toFloat() / other.toFloat());
	return (res);
}

int	Fixed::getRawBits() const
{
	return (rawBits_);
}

void	Fixed::setRawBits(int const raw)
{
	rawBits_ = raw;
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
