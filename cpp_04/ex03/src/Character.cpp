/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:51:41 by lucca             #+#    #+#             */
/*   Updated: 2026/09/08 12:47:59 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void): name_("")
{
	for (int i = 0; i < INVENTORY_LEN; i++)
		inventory_[i] = NULL;
};

Character::Character(std::string const & name): name_(name)
{
	for (int i = 0; i < INVENTORY_LEN; i++)
		inventory_[i] = NULL;
};

Character::Character(Character const & other)
{
	*this = other;
}

Character&	Character::operator=(Character const & other)
{
	if (this != &other)
	{
		name_ = other.name_;
		for (int i = 0; i < INVENTORY_LEN; i++)
		{
			if (inventory_[i] != NULL)
			{
				delete inventory_[i];
				inventory_[i] = NULL;
			}
			if (other.inventory_[i] != NULL)
				inventory_[i] = other.inventory_[i]->clone();
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < INVENTORY_LEN; i++)
	{
		if (inventory_[i] != NULL)
			delete inventory_[i];
	}
};

std::string const & Character::getName(void)	const
{
	return name_;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < INVENTORY_LEN; i++)
	{
		if (inventory_[i] == NULL)
		{
			inventory_[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_LEN || inventory_[idx] == NULL)
		return ;
	inventory_[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= INVENTORY_LEN || inventory_[idx] == NULL)
		return ;
	inventory_[idx]->use(target);
}
