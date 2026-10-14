/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:31:34 by lucca             #+#    #+#             */
/*   Updated: 2026/10/12 10:30:48 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data
{
	private:
		std::string	_name;

	public:
		Data();
		Data(const std::string& name);
		Data(const Data& other);
		Data&	operator=(const Data& other);
		~Data();

	const std::string&	getName() const;
};

#endif
