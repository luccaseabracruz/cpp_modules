/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 17:15:26 by lucca             #+#    #+#             */
/*   Updated: 2026/10/01 18:27:54 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP 
# define INTERN_HPP 

#include "AForm.hpp"
class	Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern();

		class	UnkownFormException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		AForm	*makeForm(const std::string& name, const std::string& target) const;

	private:
		static AForm	*createShrubberyCreation(const std::string& target);
		static AForm	*createPresidentialPardon(const std::string& target);
		static AForm	*createRobotomyRequest(const std::string& target);

		struct Recipe
		{
			const std::string	name;
			AForm				*(*createFunction)(const std::string& target);
		};
		static const Recipe	_table[3];
};

#endif
