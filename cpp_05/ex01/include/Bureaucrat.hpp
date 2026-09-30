/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:28:56 by lucca             #+#    #+#             */
/*   Updated: 2026/09/29 18:22:55 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

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
		
		std::string	getName()	const;
		int			getGrade()	const;

		void	incrementGrade();
		void	decrementGrade(void);
		void	signForm(Form& form) const;
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
