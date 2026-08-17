/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 10:54:08 by lucca             #+#    #+#             */
/*   Updated: 2026/08/17 11:11:34 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::string;

int	main(void)
{
	const string	str = "HI THIS IS BRAIN";
	const string	*stringPTR = &str;
	const string	&stringREF = str;

	cout << "memory address of the string variable: " << &str << '\n';
	cout << "memory address held by stringPTR:      " << stringPTR << '\n';
	cout << "memory address held by stringREF:      " << &stringREF << '\n';

	cout << '\n';

	cout << "value of the string variable:  " << str << '\n';
	cout << "value pointed to by stringPTR: " << *stringPTR << '\n';
	cout << "value pointed to by stringREF: " << stringREF << '\n';
	return (0);
}
