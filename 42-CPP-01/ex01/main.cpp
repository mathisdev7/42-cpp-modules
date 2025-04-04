/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:55:29 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/18 19:35:39 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int main()
{
	Zombie *horde;
	int zombies = 10;

	std::cout << "-----------" << std::endl;
	std::cout << "First Test" << std::endl;
	horde = zombieHorde(zombies, "Frost");
	if (horde == NULL)
		return (1);
	for (int i = 0; i < zombies; ++i)
		horde[i].announce();
	delete[] horde;
	std::cout << "-----------" << std::endl;
	std::cout << "Second Test" << std::endl;
	horde = zombieHorde(0, "Should fail");
	std::cout << "-----------" << std::endl;
	return (0);
}
