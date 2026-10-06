/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:24:00 by lucca             #+#    #+#             */
/*   Updated: 2026/10/06 12:46:14 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

void	ShrubberyCreationForm::action() const
{
	const std::string filename = _target + "_shrubbery"; 
	std::ofstream	out(filename.c_str());
	if (!out.is_open())
	{
		throw std::runtime_error(
			"Error: ShrubberyCreationForm::action(): Cannot open "
			+ filename + " file.\n"
		);
	}
	out <<	"           ^^                  \n"
			"  ^^      ^^^^       ^^        \n"
			" ^^^^    ^^^^^^     ^^^^    ^^ \n"
			"^^^^^^  ^^^^^^^^   ^^^^^^  ^^^^\n"
			"  ||       ||        ||     || \n";
	out.close();
}

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
{
	*this = other;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string&	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

