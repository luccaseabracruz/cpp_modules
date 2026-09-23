/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:08:45 by lseabra-          #+#    #+#             */
/*   Updated: 2026/09/23 12:11:43 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include <string>

void	printSection(const std::string& title);
void	printHeader(const std::string& title);

int	testAnimal();
int	testCat();
int	testDog();
int	testWrongAnimal();

#endif
