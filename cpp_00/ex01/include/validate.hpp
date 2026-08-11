/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 11:27:36 by lucca             #+#    #+#             */
/*   Updated: 2026/08/10 16:19:49 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_HPP
# define VALIDATE_HPP

typedef bool	(*Validator)(const std::string&);

bool	isNotEmptyField(const std::string& str);
bool	validatePhoneNumber(const std::string& phoneNumber);
bool	validateIndex(const std::string& index, int counter);

#endif