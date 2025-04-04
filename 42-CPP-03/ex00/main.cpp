/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:33:47 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/20 12:19:21 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <sstream>

int main()
{
	std::string name = "Frost-";
	ClapTrap one;
	ClapTrap two("fortytwo");
	one.attack("frost");
	one.takeDamage(10);
	one.takeDamage(10);
	one.beRepaired(2);
	one.attack("other frost");
	two.beRepaired(1);
	for (int i = 0; i < 6; i++)
	{
		std::stringstream ss;
		ss << i;
		two.attack(name.append(ss.str()));
	}
	two.beRepaired(2);
	return (0);
}
