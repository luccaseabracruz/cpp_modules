/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 18:07:29 by lucca             #+#    #+#             */
/*   Updated: 2026/10/01 15:43:35 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Default"), _isSigned(false), _reqSignGrade(150), _reqExecGrade(150)
{}

AForm::AForm(const std::string& name, int reqSignGrade, int reqExecGrade)
	: _name(name), _isSigned(false), _reqSignGrade(reqSignGrade),
	_reqExecGrade(reqExecGrade)
{
	if (_reqSignGrade > 150 || _reqExecGrade > 150)
		throw AForm::GradeTooLowException();
	else if (_reqSignGrade < 1 || _reqExecGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _reqSignGrade(other._reqSignGrade),
	_reqExecGrade(other._reqExecGrade)
{
	*this = other;
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm(){}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: grade out of range: too high.");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: grade out of range: too low.");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("AForm: cannot execute form because it was not signed yet.");
}

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getReqSignGrade() const
{
	return (_reqSignGrade);
}

int	AForm::getReqExecGrade() const
{
	return (_reqExecGrade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	int	bGrade = bureaucrat.getGrade();

	if (bGrade > _reqSignGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (_isSigned == false)
		throw FormNotSignedException();
	if (executor.getGrade() > _reqExecGrade)
		throw GradeTooLowException();
	this->action();
}

std::ostream&	operator<<(std::ostream& out, const AForm& form)
{
	out	<< "Name: " << form.getName()
		<< "; Is Signed: " << (form.getIsSigned() ? "True" : "False" )
		<< "; Required Grade to Sign: " << form.getReqSignGrade()
		<< "; Required Grade to Execute: " << form.getReqExecGrade() << std::endl;
	return (out);
}
