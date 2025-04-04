/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:40:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/26 11:56:56 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Base Destructor called" << std::endl;
}

Base *generate(void)
{
	int randomNum = rand() % 3;
	switch (randomNum)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	default:
		return NULL;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
	A *a = dynamic_cast<A *>(&p);
	if (a != NULL)
	{
		std::cout << "A" << std::endl;
		return;
	}

	B *b = dynamic_cast<B *>(&p);
	if (b != NULL)
	{
		std::cout << "B" << std::endl;
		return;
	}

	C *c = dynamic_cast<C *>(&p);
	if (c != NULL)
	{
		std::cout << "C" << std::endl;
		return;
	}
	std::cout << "Unknown type" << std::endl;
}
