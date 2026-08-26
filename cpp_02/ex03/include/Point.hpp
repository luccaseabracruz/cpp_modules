/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 13:57:11 by lucca             #+#    #+#             */
/*   Updated: 2026/08/26 15:12:18 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

/**
 * @brief Two-dimensional point defined by fixed-point coordinates.
 *
 * The point stores an x and y value for geometric calculations and position
 * checks in a Cartesian plane.
 */
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

/**
 * @brief Evaluates whether a point belongs to the triangle formed by three vertices.
 *
 * @param a First triangle vertex.
 * @param b Second triangle vertex.
 * @param c Third triangle vertex.
 * @param point Point to evaluate.
 * @return true if the point is inside the triangle, false otherwise.
 */
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
