/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 07:19:11 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/21 07:54:47 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Idea";
	std::cout << "Brain Constructor called and filled with ideas" << std::endl;
}

Brain::Brain(Brain &src)
{
	std::string *src_ideas = src.getIdeas();
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src_ideas[i] + " copy";
	std::cout << "Brain Copy Constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Brain Destructor called and ideas freed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &Brain::operator=(Brain const &rhs)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string *Brain::getIdeas(void)
{
	return (this->_ideas);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
