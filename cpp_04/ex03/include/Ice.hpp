/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:08:05 by lucca             #+#    #+#             */
/*   Updated: 2026/09/08 11:47:17 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(Ice const & other);
		Ice&	operator=(Ice const & other);
		~Ice(void);

		AMateria*	clone(void)	const;
		void use(ICharacter& target);
};

#endif