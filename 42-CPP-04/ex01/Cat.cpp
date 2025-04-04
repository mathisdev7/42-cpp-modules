/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 07:00:47 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/21 07:57:01 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Default Cat Constructor called with " << this->getType() << std::endl;
}

Cat::Cat(Cat &src) : Animal(src)
{
	this->_type = src.getType();
	this->_brain = new Brain(*(src.getBrain()));
	std::cout << "Copy Constructor called for Cat" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete _brain;
	std::cout << "Default Cat Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &Cat::operator=(Cat const &rhs)
{
	this->_type = rhs.getType();
	if (this->_brain)
		delete[] (this->_brain);
	this->_brain = new Brain(*(rhs.getBrain()));
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::catCompare(Cat const &other_cat) const
{
	std::cout << std::endl;
	std::cout << "Now comparing two cats\n";
	std::cout << "My brain's heap address: " << static_cast<void *>(this->_brain) << std::endl;
	std::cout << "Other's heap address: " << static_cast<void *>(other_cat.getBrain()) << std::endl;
	std::cout << std::endl;
	std::cout << "My brain's ideas \t\t | \t\t\t Other brain's ideas\n";
	for (int i = 0; i < 100; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((this->_brain)->getIdeas())[i] << "\t\t\t | \t\t\t" << ((other_cat.getBrain())->getIdeas())[i] << std::endl;
	std::cout << std::endl;
}

std::string Cat::getType(void) const
{
	return (this->_type);
}

Brain *Cat::getBrain(void) const
{
	return (this->_brain);
}

void Cat::makeSound(void) const
{
	std::cout << "Cat sound...Meow!" << std::endl;
}

/* ************************************************************************** */
