/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:33:47 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/20 13:06:50 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
	std::cout << "--------------------" << std::endl;
	ScavTrap three;
	ScavTrap four("Atom");

	three.attack("fortyone");
	three.beRepaired(22);
	three.takeDamage(21);
	three.beRepaired(22);
	three.guardGate();
	three.guardGate();
	four.attack("Atom-0");
	four.takeDamage(101);
	four.takeDamage(15);
	four.attack("fortyone-0");

	std::cout << "--------------------" << std::endl;
	FragTrap five;
	FragTrap six("Blud");

	five.highFiveGuys();
	five.attack("Linux");
	five.takeDamage(101);
	five.takeDamage(1);
	five.attack("Ubuntu");
	six.highFiveGuys();
	return (0);
}
