/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:04:49 by lucca             #+#    #+#             */
/*   Updated: 2026/08/20 19:36:37 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					rawBits_;
		static const int	fractBitsN_;

	public:
		Fixed(void);							// default constructor
		Fixed(const Fixed& other);				// copy constructor
		Fixed& operator=(const Fixed& other);	// copy assignment operator overload
		~Fixed();								// destructor

		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif