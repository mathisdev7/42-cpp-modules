/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 07:00:47 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/21 07:43:21 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Default Cat Constructor called with " << this->getType() << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Copy Constructor called for Cat" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Default Cat Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &Cat::operator=(Cat const &rhs)
{
	this->_type = rhs.getType();
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Cat::getType(void) const
{
	return (this->_type);
}

void Cat::makeSound(void) const
{
	std::cout << "Cat sound...Meow!" << std::endl;
}

/* ************************************************************************** */
