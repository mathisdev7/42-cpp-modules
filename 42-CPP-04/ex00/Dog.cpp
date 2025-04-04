/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 07:00:47 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/21 07:43:27 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Default Dog Constructor called with " << this->getType() << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	this->_type = src.getType();
	std::cout << "Copy Constructor called with " << this->getType() << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "Default Dog Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &Dog::operator=(Dog const &rhs)
{
	this->_type = rhs.getType();
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Dog::getType(void) const
{
	return (this->_type);
}

void Dog::makeSound(void) const
{
	std::cout << "Dog sound...Ouaf!" << std::endl;
}

/* ************************************************************************** */
