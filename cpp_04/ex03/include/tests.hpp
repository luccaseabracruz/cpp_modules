/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:35:07 by lucca             #+#    #+#             */
/*   Updated: 2026/09/10 14:44:29 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include <string>

void	printSection(const std::string& title);
void	printHeader(const std::string& title);
int		test(int (*function)(void), const std::string& title);
int		subjectTest(void);
int		testDeepCopy(void);
int		runMyTests(void);

#endif
