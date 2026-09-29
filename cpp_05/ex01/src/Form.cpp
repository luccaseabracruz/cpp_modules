/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 18:07:29 by lucca             #+#    #+#             */
/*   Updated: 2026/09/29 13:39:09 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("Default"), _isSigned(false), _reqSignGrade(150), _reqExecGrade(150)
{
	
}

Form::Form(const std::string& name, int reqSignGrade, int reqExecGrade)
	: _name(name), _isSigned(false), _reqSignGrade(reqSignGrade),
	_reqExecGrade(reqExecGrade)
{
	if (_reqSignGrade > 150 || _reqExecGrade > 150)
		throw Form::GradeTooLowException();
	else if (_reqSignGrade < 1 || _reqExecGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& other)
	: _name(other._name), _reqSignGrade(other._reqSignGrade),
	_reqExecGrade(other._reqExecGrade)
{
	*this = other;
}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form(){}

const char*	Form::GradeTooHighException::what()	const throw()
{
	return ("Error: Form: grade out of range: too high.");
}

const char*	Form::GradeTooLowException::what()	const throw()
{
	return ("Error: Form: grade out of range: too low.");
}

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getReqSignGrade() const
{
	return (_reqSignGrade);
}

int	Form::getReqExecGrade() const
{
	return (_reqExecGrade);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	int	bGrade = bureaucrat.getGrade();

	if (bGrade > _reqSignGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
	out	<< "Name: " << form.getName()
		<< "; Is Signed: " << (form.getIsSigned() ? "True" : "False" )
		<< "; Required Grade to Sign: " << form.getReqSignGrade()
		<< "; Required Grade to Execute: " << form.getReqExecGrade() << std::endl;
	return (out);
}
