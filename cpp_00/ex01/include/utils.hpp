/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:33:15 by lucca             #+#    #+#             */
/*   Updated: 2026/08/07 20:25:46 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

# define MSG_OPERATION "Choose a command (ADD | SEARCH | EXIT): "
# define ERR_PREFIX "[Error] "
# define INV_INPUT "invalid input"

bool	getInput(const std::string& msg, std::string& input);
bool	createContact(Contact contact);

#endif