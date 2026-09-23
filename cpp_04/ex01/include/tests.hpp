/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 13:47:50 by lseabra-          #+#    #+#             */
/*   Updated: 2026/09/23 14:53:23 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include <string>

void	printSection(const std::string& title);
void	printHeader(const std::string& title);
int		test(int (*function)(void), const std::string& title);

int	subjectTest();
int	testAnimal();
int	testBrain();
int	testDog();
int	testCat();

#endif