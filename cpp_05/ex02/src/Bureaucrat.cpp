/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:44:34 by lucca             #+#    #+#             */
/*   Updated: 2026/09/29 18:23:30 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("NoName"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade)
{
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

const char*	Bureaucrat::GradeTooHighException::what()	const throw()
{
	return ("Error: Bureaucrat: grade out of range: too high.");
}

const char*	Bureaucrat::GradeTooLowException::what()	const throw()
{
	return ("Error: Bureaucrat: grade out of range: too low.");
}

std::string	Bureaucrat::getName()	const
{
	return (_name);
}

int	Bureaucrat::getGrade()	const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	else
		_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	else
		_grade += 1;
}

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << '\n';
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cout	<< _name << " couldn’t sign " << form.getName()
					<< " because form requires a higher grade.\n";
	}
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out	<< bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << '.';
	return out;
}
