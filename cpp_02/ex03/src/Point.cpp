/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:31:30 by lucca             #+#    #+#             */
/*   Updated: 2026/08/25 15:13:24 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

//----------------------- Special Member Functions ---------------------------//
Point::Point(): x(Fixed(0)), y(Fixed(0)){}

Point::Point(float initialX, float initialY)
: x(Fixed(initialX)), y(Fixed(initialY)) {}

Point::Point(const Point& other): x(other.getX()), y(other.getY()){}

Point&	Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

Point::~Point(){}

//--------------------------- Member Functions -------------------------------//
const Fixed& Point::getX() const
{
	return (x);
}

const Fixed& Point::getY() const
{
	return (y);
}
