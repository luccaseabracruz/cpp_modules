/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:59:49 by lucca             #+#    #+#             */
/*   Updated: 2026/09/07 20:47:03 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AAnimal_HPP
# define AAnimal_HPP

# include <iostream>

# define AAnimal_PFX	"[AAnimal] "
# define DOG_PFX	"[DOG] "
# define CAT_PFX	"[CAT] "

class	AAnimal
{
	protected:
		std::string type;

	public:
		AAnimal(void);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual	~AAnimal(void);

		virtual void	makeSound(void)	const = 0;

		std::string	getType(void)	const;
};

#endif
