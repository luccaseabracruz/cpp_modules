/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:34:41 by lucca             #+#    #+#             */
/*   Updated: 2026/08/24 21:34:31 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::fractBitsN_ = 8;

//----------------------------- Special Members ------------------------------//
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


//--------------------------- Comparison Operators ---------------------------//
bool	Fixed::operator==(const Fixed& other) const
{
	return (rawBits_ == other.getRawBits());
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (rawBits_ > other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (rawBits_ >= other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (rawBits_ < other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (rawBits_ <= other.getRawBits());
}

//--------------------------- Arithmetic Operators ---------------------------//
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed	res;
	
	res.setRawBits(this->rawBits_ + other.getRawBits());
	return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed	res;
	
	res.setRawBits(this->rawBits_ - other.getRawBits());
	return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed	res(this->toFloat() * other.toFloat());
	return (res);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed	res(this->toFloat() / other.toFloat());
	return (res);
}

//---------------------- Increment/Decrement Operators -----------------------//
Fixed& Fixed::operator++(void)
{
	rawBits_++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	++(*this);
	return (temp);
}

Fixed& Fixed::operator--(void)
{
	rawBits_--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	--(*this);
	return (temp);
}

//----------------------------- Member Functions -----------------------------//
int	Fixed::getRawBits() const
{
	return (rawBits_);
}

void	Fixed::setRawBits(int const raw)
{
	rawBits_ = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(rawBits_) / (1 << fractBitsN_));
}

int Fixed::toInt(void) const
{
	return (rawBits_ >> fractBitsN_);
}

//----------------------------- Stream Operators -----------------------------//
std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
