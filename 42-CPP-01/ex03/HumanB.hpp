/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:38:50 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/19 09:20:25 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./Weapon.hpp"

#pragma once

class HumanB
{
private:
	std::string _name;
	Weapon *weapon;

public:
	void attack(void) const;
	void setWeapon(Weapon &weapon);
	std::string getName(void) const;
	HumanB(std::string name);
	~HumanB(void);
};
