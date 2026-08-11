/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:28:28 by lucca             #+#    #+#             */
/*   Updated: 2026/08/10 16:53:05 by lucca            ###   ########.fr       */
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
		void	putItem_(const std::string& str, bool endPipe) const;
		void	displayContacts_() const;
	public:
		PhoneBook();
		~PhoneBook();
		bool	addContact();
		bool	searchContact() const;
};

#endif