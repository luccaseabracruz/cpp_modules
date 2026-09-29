/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 16:50:24 by lucca             #+#    #+#             */
/*   Updated: 2026/09/28 18:44:44 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_reqSignGrade;
	const int			_reqExecGrade;
public:
	Form();
	Form(const std::string& name, int reqSignGrade, int reqExecGrade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	class	GradeTooHighException: public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};

	class	GradeTooLowException: public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getReqSignGrade() const;
	int			getReqExecGrade() const;

	void	beSigned(const Bureaucrat& bureaucrat);
};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif
