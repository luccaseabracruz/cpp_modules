/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 11:27:36 by lucca             #+#    #+#             */
/*   Updated: 2026/08/10 12:00:08 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_HPP
# define VALIDATE_HPP

typedef bool	(*Validator)(const std::string&);

bool	isNotEmptyField(const std::string& str);
bool	validatePhoneNumber(const std::string& phoneNumber);

#endif