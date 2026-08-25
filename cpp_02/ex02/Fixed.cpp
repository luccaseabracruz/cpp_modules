/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:34:41 by lucca             #+#    #+#             */
/*   Updated: 2026/08/25 11:19:17 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

//--------------------------- Member Variables -------------------------------//
const int	Fixed::fractBitsN_ = 8;

//------------------------ Special Member Functions --------------------------//
Fixed::Fixed(void): rawBits_(0)
{
}

Fixed::Fixed(const int iValue)
{
	rawBits_ = iValue << fractBitsN_;
}

Fixed::Fixed(const float fValue)
{
	rawBits_ = static_cast<int>(roundf(fValue * (1 << fractBitsN_)));
}


Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	this->rawBits_ = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
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

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}

//----------------------------- Stream Operators -----------------------------//
std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
