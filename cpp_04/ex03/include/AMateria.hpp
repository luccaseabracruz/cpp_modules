/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 00:04:04 by lucca             #+#    #+#             */
/*   Updated: 2026/09/08 11:11:11 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type_;

	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & other);
		AMateria&	operator=(AMateria const & other);
		~AMateria(void);

		std::string const & getType(void) const; //Returns the materia type
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
};

#endif
