/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:28:28 by lucca             #+#    #+#             */
/*   Updated: 2026/08/10 15:15:39 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact contacts_[8];
		int		counter_;
		void	putItem_(const std::string& str, bool endPipe);
		void	displayContacts_();
	public:
		PhoneBook();
		~PhoneBook();
		bool	addContact();
		bool	searchContact();
};

#endif