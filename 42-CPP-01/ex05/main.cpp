/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:22:46 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/18 19:38:25 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./Harl.hpp"
#include <cstdlib>

int main()
{
	Harl harl;

	std::cout << "Harl talks a lot." << std::endl
			  << std::endl;
	harl.complain("ERROR");
	harl.complain("something else");
	std::cout << "Select a level to make Harl talk." << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "level: ";
		std::string input;
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cerr << "Exit..." << std::endl;
			exit(1);
		}
		harl.complain(input);
		std::cout << std::endl;
	}
	return (1);
}
