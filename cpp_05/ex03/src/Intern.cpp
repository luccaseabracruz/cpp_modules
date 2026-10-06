/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 17:18:52 by lucca             #+#    #+#             */
/*   Updated: 2026/10/06 12:36:31 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)	other;

	return (*this);
}

Intern::~Intern(){}

const char*	Intern::UnkownFormException::what() const throw()
{
	return ("Intern: cannot create form: unkown form name.");
}

AForm	*Intern::makeForm(const std::string& name, const std::string& target) const
{
	std::size_t	tableLen = sizeof(_table) / sizeof(_table[0]);

	for (std::size_t i = 0; i < tableLen; i++)
	{
		if (_table[i].name == name)
		{
			std::cout << "Intern creates " << name << ".\n";
			return (_table[i].createFunction(target));
		}
	}
	std::cerr << "Error: Intern::makeForm: unkown/invalid form name: \"" << name << "\".\n";
	throw UnkownFormException();
}

AForm	*Intern::createShrubberyCreation(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createPresidentialPardon(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::createRobotomyRequest(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

const Intern::Recipe Intern::_table[3] = {
	{"shrubbery creation", &Intern::createShrubberyCreation},
	{"presidential pardon", &Intern::createPresidentialPardon},
	{"robotomy request", &Intern::createRobotomyRequest}
};
