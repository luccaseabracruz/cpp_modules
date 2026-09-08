/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:05:06 by lucca             #+#    #+#             */
/*   Updated: 2026/09/08 12:20:45 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# define INVENTORY_LEN	4

class	Character: public ICharacter
{
	private:
		std::string	name_;
		AMateria	*inventory_[INVENTORY_LEN];
	public:
		Character(void);
		Character(std::string const & name);
		Character(Character const & other);
		Character&	operator=(Character const & other);
		~Character(void);

		std::string const & getName(void)	const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif