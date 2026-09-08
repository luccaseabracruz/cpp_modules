/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:47:32 by lucca             #+#    #+#             */
/*   Updated: 2026/09/08 11:47:55 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(Cure const & other);
		Cure&	operator=(Cure const & other);
		~Cure(void);

		AMateria*	clone(void)	const;
		void use(ICharacter& target);
};

#endif