/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:35:08 by lucca             #+#    #+#             */
/*   Updated: 2026/09/09 11:31:02 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

# define KNOWN_MATERIAS_LEN 4

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*knownMaterias_[KNOWN_MATERIAS_LEN];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & other);
		MateriaSource&	operator=(MateriaSource const & other);
		~MateriaSource(void);

		void learnMateria(AMateria *materia);
		AMateria* createMateria(std::string const & type)	const;
};

#endif