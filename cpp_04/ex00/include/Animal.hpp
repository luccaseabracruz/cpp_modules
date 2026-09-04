/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:59:49 by lucca             #+#    #+#             */
/*   Updated: 2026/09/04 17:27:13 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define ANIMAL_PFX	"[ANIMAL] "
# define DOG_PFX	"[DOG] "
# define CAT_PFX	"[CAT] "

class	Animal
{
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual	~Animal(void);

		virtual void	makeSound(void);

		std::string	getType(void)	const;
};

#endif
