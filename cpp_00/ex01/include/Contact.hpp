/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:07:31 by lseabra-          #+#    #+#             */
/*   Updated: 2026/08/08 11:56:33 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class	Contact
{
	private:
		std::string	firstName_;
		std::string	lastName_;
		std::string	nickname_;
		std::string	phoneNumber_;
		std::string	darkestSecret_;
	public:
		Contact(void);
		Contact(const std::string& firstName, const std::string& lastName, 
				const std::string& nickname, const std::string& phoneNumber,
				const std::string& darkestSecret);
		~Contact();
};

#endif
