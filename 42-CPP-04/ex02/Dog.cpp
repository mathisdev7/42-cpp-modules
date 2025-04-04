/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 07:00:47 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/21 07:56:49 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Default Dog Constructor called with " << this->getType() << std::endl;
}

Dog::Dog(Dog &src) : Animal(src)
{
	this->_type = src.getType();
	this->_brain = new Brain(*(src.getBrain()));
	std::cout << "Copy Constructor called for Dog" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete _brain;
	std::cout << "Default Dog Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &Dog::operator=(Dog const &rhs)
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

void Dog::dogCompare(Dog const &other_dog) const
{
	std::cout << std::endl;
	std::cout << "Now comparing two dogs\n";
	std::cout << "My brain's heap address: " << static_cast<void *>(this->_brain) << std::endl;
	std::cout << "Other's heap address: " << static_cast<void *>(other_dog.getBrain()) << std::endl;
	std::cout << std::endl;
	std::cout << "My brain's ideas \t\t | \t\t\t Other brain's ideas\n";
	for (int i = 0; i < 100; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((this->_brain)->getIdeas())[i] << "\t\t\t | \t\t\t" << ((other_dog.getBrain())->getIdeas())[i] << std::endl;
	std::cout << std::endl;
}

std::string Dog::getType(void) const
{
	return (this->_type);
}

Brain *Dog::getBrain(void) const
{
	return (this->_brain);
}

void Dog::makeSound(void) const
{
	std::cout << "Dog sound...Meow!" << std::endl;
}

/* ************************************************************************** */
