/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:32:24 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/26 15:34:26 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	Array<int> numbers(3);
	std::cout << "Numbers array size: " << numbers.size() << std::endl;
	std::cout << "Default initialized values: " << numbers[0] << " " << numbers[1] << " " << numbers[2] << std::endl;

	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;

	Array<int> copy(numbers);
	std::cout << "Copy array values: " << copy[0] << " " << copy[1] << " " << copy[2] << std::endl;

	copy[0] = 100;
	std::cout << "Original array after modifying copy: " << numbers[0] << std::endl;
	std::cout << "Modified copy: " << copy[0] << std::endl;

	Array<int> assigned = numbers;
	std::cout << "Assigned array values: " << assigned[0] << " " << assigned[1] << " " << assigned[2] << std::endl;

	try
	{
		numbers[50] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
