/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:46:47 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/18 19:35:51 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Hi, my name is " << name << " and I am not a zombie, really." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Damn, I (" << _name << ") really was one." << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n"
			  << std::endl;
}
