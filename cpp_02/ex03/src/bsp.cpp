/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:03:56 by lucca             #+#    #+#             */
/*   Updated: 2026/09/21 18:35:40 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

struct	TriangleS
{
	float	aX;
	float	aY;
	float	bX;
	float	bY;
	float	cX;
	float	cY;
	
};

static TriangleS	initTriangleT(const Point& a, const Point& b, const Point& c)
{
	TriangleS	t = {
		a.getX().toFloat(),
		a.getY().toFloat(),
		b.getX().toFloat(),
		b.getY().toFloat(),
		c.getX().toFloat(),
		c.getY().toFloat(),
	};
	return (t);
}

/**
 * @brief Tests whether a point lies strictly inside a triangle.
 *
 * Computes the signed orientation of the point relative to each edge of the
 * triangle. If the point is on an edge, the orientation is zero and it is
 * rejected. Otherwise, the point is inside only if all three orientation
 * values have the same sign, meaning it lies on the same side of every edge.
 *
 * @param a First vertex of the triangle.
 * @param b Second vertex of the triangle.
 * @param c Third vertex of the triangle.
 * @param point Point to test.
 * @return true if the point is strictly inside the triangle, false otherwise.
 */
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	TriangleS	t = initTriangleT(a, b, c);
	float	pX = point.getX().toFloat();
	float	pY = point.getY().toFloat();
	float	d1 = (t.bX - t.aX) * (pY - t.aY) - (t.bY - t.aY) * (pX - t.aX);
	float	d2 = (t.cX - t.bX) * (pY - t.bY) - (t.cY - t.bY) * (pX - t.bX);
	float	d3 = (t.aX - t.cX) * (pY - t.cY) - (t.aY - t.cY) * (pX - t.cX);

	if (d1 == 0 || d2 == 0 || d3 == 0)
		return (false);
	else if ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0))
		return (true);
	return (false);
}
