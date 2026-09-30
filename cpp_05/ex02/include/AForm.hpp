/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 16:50:24 by lucca             #+#    #+#             */
/*   Updated: 2026/09/30 13:00:40 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_reqSignGrade;
		const int			_reqExecGrade;

		virtual void	action() const = 0;

	public:
		AForm();
		AForm(const std::string& name, int reqSignGrade, int reqExecGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();

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

	class	FormNotSignedException: public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getReqSignGrade() const;
	int			getReqExecGrade() const;

	void	beSigned(const Bureaucrat& bureaucrat);
	void	execute(Bureaucrat const & executor);
};

std::ostream&	operator<<(std::ostream& out, const AForm& form);

#endif
