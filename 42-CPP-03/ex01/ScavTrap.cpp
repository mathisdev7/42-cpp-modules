/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:25:56 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/20 13:02:25 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"
#include "./ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	this->_guarding_gate = false;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Default destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	this->_guarding_gate = false;
	std::cout << "ScavTrap Name Parameter constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	this->_guarding_gate = src._guarding_gate;
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->getEnergy() > 0 && this->getHealth() > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->getDamage() << " points of damage!" << std::endl;
		this->setEnergy(this->_energy - 1);
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack " << target << ", no energy/health left!" << std::endl;
	}
}
void ScavTrap::guardGate(void)
{
	if (this->_guarding_gate == false)
	{
		this->_guarding_gate = true;
		std::cout << "ScavTrap " << this->_name << " is now guarding the gate!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is already guarding the gate!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_health = src._health;
	this->_energy = src._energy;
	this->_damage = src._damage;
	return (*this);
}
