/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:39:23 by lucca             #+#    #+#             */
/*   Updated: 2026/08/25 11:17:09 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <fstream>

class Fixed
{
	private:
		// Member Variables
		static const int	fractBitsN_;
		int					rawBits_;

	public:
		// Special Member Functions
		Fixed();								// default	constructor
		Fixed(const int rawBits);				// int		constructor
		Fixed(const float rawBits);				// float	constructor
		Fixed(const Fixed& other);				// copy		constructor
		Fixed&	operator=(const Fixed& other);	// copy assignment operator overload
		~Fixed();								// destructor

		// Member Functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	};

//Stream Operators
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif