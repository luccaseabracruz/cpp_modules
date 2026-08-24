/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:34:48 by lucca             #+#    #+#             */
/*   Updated: 2026/08/24 17:38:03 by lucca            ###   ########.fr       */
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

		friend std::ostream& operator<<(std::ostream& out, Fixed const& fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

#endif