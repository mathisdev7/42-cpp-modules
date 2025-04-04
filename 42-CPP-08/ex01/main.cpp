/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:10:05 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/27 15:22:22 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <iostream>

int main()
{
	try
	{
		std::cout << "=== Test with addNumber ===" << std::endl;
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		sp.addNumber(42); // should throw an error, too much numbers
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n=== Test with addNumbers ===" << std::endl;
		Span sp2(10);
		std::vector<int> numbers;
		numbers.push_back(10);
		numbers.push_back(20);
		numbers.push_back(30);
		numbers.push_back(40);
		numbers.push_back(50);

		sp2.addNumbers(numbers.begin(), numbers.end());

		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n=== Test with 4 numbers when the max is 3 ===" << std::endl;
		Span sp3(3);
		std::vector<int> tooMany;
		tooMany.push_back(1);
		tooMany.push_back(2);
		tooMany.push_back(3);
		tooMany.push_back(4); // should throw an error, too much numbers

		sp3.addNumbers(tooMany.begin(), tooMany.end());
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
