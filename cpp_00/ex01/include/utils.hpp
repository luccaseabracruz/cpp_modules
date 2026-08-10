/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:33:15 by lucca             #+#    #+#             */
/*   Updated: 2026/08/10 15:33:39 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include "Contact.hpp"

# define MSG_OPERATION "Choose a command (ADD | SEARCH | EXIT): "
# define ERR_PREFIX "[Error] "
# define INV_INPUT "invalid input"

bool	getInput(const std::string& msg, std::string& input);
bool	createContact(Contact& contact);
bool	putErr(const std::string& msg);

#endif