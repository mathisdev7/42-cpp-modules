/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:40:12 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/18 19:35:51 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;

public:
	void announce(void) const;
	Zombie(std::string name);
	~Zombie(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);
