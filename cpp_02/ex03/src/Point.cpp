/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 13:58:25 by lucca             #+#    #+#             */
/*   Updated: 2026/08/25 14:28:37 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//----------------------- Special Member Functions ---------------------------//
Point::Point(): x(Fixed(0)), y(Fixed(0))
{
}

Point::Point(float initialX, float initialY)
: x(Fixed(initialX)), y(Fixed(initialY))
{
}

Point::Point(const Point& other)
{
	(void)other;
}

Point&	Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{
	
}

//--------------------------- Member Functions -------------------------------//
const Fixed Point::getX()
{
	return (x);
}

const Fixed Point::getY()
{
	return (y);
}
