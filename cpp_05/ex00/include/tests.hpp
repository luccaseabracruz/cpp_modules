/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 19:53:54 by lucca             #+#    #+#             */
/*   Updated: 2026/09/18 11:54:12 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include <iostream>

void	printHeader(const std::string& title, int headerType);
int		test(const std::string& title, int (*testFun)(), int headerType);
int		testGrade();
int		testGetters();
int		testSpecialMembers();

#endif
