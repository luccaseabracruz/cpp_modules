/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 19:42:30 by lucca             #+#    #+#             */
/*   Updated: 2026/09/07 11:39:30 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "[Brain] Constructor being called\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "[Brain] Copy Constructor being called\n";

	*this = other;
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "[Brain] Copy Assigment Operator being called\n";
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "[Brain] Destructor being called\n";
}

std::string	Brain::getIdea(int idx)	const
{
	if (idx < 0 || idx >= MAX_IDEAS)
		throw std::out_of_range("Brain::getIdea: index out of range.");
	return ideas[idx];
}

void	Brain::setIdea(int idx, std::string idea)
{
	if (idx < 0 || idx >= MAX_IDEAS)
		throw std::out_of_range("Brain::setIdea: index out of range.");
	ideas[idx] = idea;
}
