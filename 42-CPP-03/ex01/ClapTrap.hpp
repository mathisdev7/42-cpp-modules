/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:21:24 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/20 12:46:44 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

class ClapTrap
{
protected:
	std::string _name;
	unsigned int _health;
	unsigned int _energy;
	unsigned int _damage;

public:
	ClapTrap(std::string name);
	ClapTrap(void);
	ClapTrap(const ClapTrap &src);
	ClapTrap &operator=(const ClapTrap &src);
	~ClapTrap(void);
	unsigned int getHealth(void);
	unsigned int getEnergy(void);
	unsigned int getDamage(void);
	void setHealth(int health);
	void setEnergy(int energy);
	void setDamage(int damage);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
