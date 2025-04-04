/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:25:56 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/20 13:04:30 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"
#include "./ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Default destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "FragTrap Name Parameter constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}
void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->_name << ": Here's you high five 🙌" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_health = src._health;
	this->_energy = src._energy;
	this->_damage = src._damage;
	return (*this);
}
