/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 13:57:11 by lucca             #+#    #+#             */
/*   Updated: 2026/08/25 14:50:39 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed	x;
	const Fixed	y;
public:
	// Special Member Functions
	Point();								// Default Constructor
	Point(float x, float y);				// Constructor
	Point&	operator=(const Point& other);	// Copy Assignment Operator
	Point(const Point& other);				//Copy constructor
	~Point();

	const Fixed& getX() const;
	const Fixed& getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
