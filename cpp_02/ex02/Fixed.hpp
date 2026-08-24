/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:34:48 by lucca             #+#    #+#             */
/*   Updated: 2026/08/24 20:03:55 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <fstream>

class Fixed
{
	private:
		static const int	fractBitsN_;
		int					rawBits_;

	public:
		Fixed();							// default	constructor
		Fixed(const int rawBits);				// int		constructor
		Fixed(const float rawBits);				// float	constructor
		Fixed(const Fixed& other);				// copy		constructor
		Fixed&	operator=(const Fixed& other);	// copy assignment operator overload
		~Fixed();								// destructor

		Fixed	operator+(const Fixed& other);
		Fixed	operator-(const Fixed& other);
		Fixed	operator*(const Fixed& other);
		Fixed	operator/(const Fixed& other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const& fixed);

#endif