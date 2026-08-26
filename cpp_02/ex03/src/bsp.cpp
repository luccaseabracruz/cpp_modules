/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:03:56 by lucca             #+#    #+#             */
/*   Updated: 2026/08/26 14:44:55 by lucca            ###   ########.fr       */
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

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	TriangleS	t = initTriangleT(a, b, c);
	float	pX = point.getX().toFloat();
	float	pY = point.getY().toFloat();
	float	d1 = (t.bX - t.aX) * (pY - t.aY) - (t.bY - t.aY) * (pX - t.aX);
	float	d2 = (t.cX - t.bX) * (pY - t.bY) - (t.cY - t.bY) * (pX - t.bX);
	float	d3 = (t.aX - t.cX) * (pY - t.cY) - (t.aY - t.cY) * (pX - t.cX);
	bool	findZero = (d1 == 0 || d2 == 0 || d3 == 0);
	bool	findPos = (d1 > 0 || d2 > 0 || d3 < 0);
	bool	findNeg = (d1 < 0 || d2 < 0 || d3 < 0);

	if (findZero || (findPos && findNeg))
		return (false);
	return (true);
}
