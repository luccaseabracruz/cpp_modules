/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:34:48 by lucca             #+#    #+#             */
/*   Updated: 2026/08/24 20:45:07 by lucca            ###   ########.fr       */
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
		// Special Members
		Fixed();							// default	constructor
		Fixed(const int rawBits);				// int		constructor
		Fixed(const float rawBits);				// float	constructor
		Fixed(const Fixed& other);				// copy		constructor
		Fixed&	operator=(const Fixed& other);	// copy assignment operator overload
		~Fixed();								// destructor

		// Comparison Operators
		bool	operator==(const Fixed& other);
		bool	operator>(const Fixed& other);
		bool	operator>=(const Fixed& other);
		bool	operator<(const Fixed& other);
		bool	operator<=(const Fixed& other);

		// Arithmetic Operators
		Fixed	operator+(const Fixed& other);
		Fixed	operator-(const Fixed& other);
		Fixed	operator*(const Fixed& other);
		Fixed	operator/(const Fixed& other);

		// Member Functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	};
	

//Stream Operators
std::ostream& operator<<(std::ostream& out, Fixed const& fixed);

#endif