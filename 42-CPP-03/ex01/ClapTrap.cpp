/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:25:56 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/20 12:18:36 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _health(10), _energy(10), _damage(0)
{
	std::cout << "Initialized " << this->_name << " Claptrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _damage(0)
{
	std::cout << "Initialized " << name << " Claptrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Default destructor called" << std::endl;
}

unsigned int ClapTrap::getHealth(void)
{
	return (this->_health);
}

unsigned int ClapTrap::getEnergy(void)
{
	return (this->_energy);
}

unsigned int ClapTrap::getDamage(void)
{
	return (this->_damage);
}

void ClapTrap::setHealth(int health)
{
	this->_health = health;
}

void ClapTrap::setEnergy(int energy)
{
	this->_energy = energy;
}

void ClapTrap::setDamage(int damage)
{
	this->_damage = damage;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->getEnergy() > 0 && this->getHealth() > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->getDamage() << " points of damage!" << std::endl;
		this->setEnergy(this->_energy - 1);
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack " << target << ", no energy/health left!" << std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHealth() > amount)
		this->setHealth(this->_health - amount);
	else if (this->getHealth() > 0)
		this->setHealth(0);
	else
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " took " << amount << " damages, " << this->getHealth() << " left!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergy() > 0 && this->getHealth() > 0 && this->getHealth() + amount <= 10)
	{
		std::cout << "ClapTrap " << this->_name << " repaired " << amount << " damages" << this->_health + amount << " left!" << std::endl;
		this->setHealth(this->_health + amount);
		this->setEnergy(this->_energy - 1);
	}
	else if (this->getEnergy() == 0 || this->getHealth() == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot repair himself, no energy/health left!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " cannot repair himself, 10 health points maximum!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_health = src._health;
	this->_energy = src._energy;
	this->_damage = src._damage;
	return *this;
}
