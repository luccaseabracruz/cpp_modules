/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 19:37:07 by lucca             #+#    #+#             */
/*   Updated: 2026/09/07 11:41:37 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

# define MAX_IDEAS	100

class	Brain
{
	private:
		std::string ideas[MAX_IDEAS];

	public:
		Brain(void);
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		~Brain(void);

		std::string	getIdea(int idx)	const;
		void	setIdea(int idx, std::string idea);
};

#endif