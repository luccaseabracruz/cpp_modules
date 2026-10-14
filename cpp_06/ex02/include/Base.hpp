/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:02:25 by lucca             #+#    #+#             */
/*   Updated: 2026/10/14 12:17:09 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		virtual	~Base(){};
};

class A: public Base {};

class B: public Base {};

class C: public Base {};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
