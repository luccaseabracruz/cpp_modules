/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:44:34 by lucca             #+#    #+#             */
/*   Updated: 2026/09/18 10:57:22 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name_("NoName"), grade_(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name_(name), grade_(grade)
{
	if (grade_ > 150)
		throw GradeTooLowException();
	else if (grade_ < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name_(other.name_)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->grade_ = other.grade_;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

const char*	Bureaucrat::GradeTooHighException::what()	const throw()
{
	return ("Error: grade out of range: too high.");
}

const char*	Bureaucrat::GradeTooLowException::what()	const throw()
{
	return ("Error: grade out of range: too low.");
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade_ <= 1)
		throw GradeTooHighException();
	else
		grade_ -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade_ + 1 > 150)
		throw GradeTooLowException();
	else
		grade_ += 1;
}

std::string	Bureaucrat::getName()	const
{
	return (name_);
}

int	Bureaucrat::getGrade()	const
{
	return (grade_);
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out	<< bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << '.';
	return out;
}
