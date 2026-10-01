/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:28:24 by lucca             #+#    #+#             */
/*   Updated: 2026/10/01 15:06:39 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

void	RobotomyRequestForm::action() const
{
	std::cout << "Whirrrrrrrrrrrrrrrrrrrr\n";
	if (rand() % 2)
		std::cout << "[SUCCESS]: " << _target << " has been robotomized.\n";
	else
		std::cout << "[FAIL]: " << _target << " robotomization went wrong.\n";
}

RobotomyRequestForm::RobotomyRequestForm()
	:AForm("RobotomyRequestForm", 72, 45), _target("Default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
{
	*this = other;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string&	RobotomyRequestForm::getTarget() const
{
	return (_target);
}
