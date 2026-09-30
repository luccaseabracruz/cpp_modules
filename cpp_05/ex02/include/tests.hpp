/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 19:53:54 by lucca             #+#    #+#             */
/*   Updated: 2026/09/30 16:46:00 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include <iostream>

void	printHeader(const std::string& title, int headerType);
int		runTest(int (*f)(), const std::string& title);
int		testBureaucrat();
int		testShrubberyCreationForm();
int		testSigning();

#endif
