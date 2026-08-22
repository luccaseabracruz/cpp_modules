/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:16:18 by lucca             #+#    #+#             */
/*   Updated: 2026/08/21 11:47:20 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

const int	Fixed::fractBitsN_ = 8;

Fixed::Fixed(void): rawBits_(0)
{
	std::cout << "Default constructor called\n";
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

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits() called\n";
	return (rawBits_);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits() called\n";
	rawBits_ = raw;
}
