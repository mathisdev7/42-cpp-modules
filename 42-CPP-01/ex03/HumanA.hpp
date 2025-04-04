/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:38:50 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/19 09:20:20 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./Weapon.hpp"

#pragma once

class HumanA
{
private:
	std::string _name;
	Weapon &weapon;

public:
	void attack(void) const;
	std::string getName(void) const;
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
};
