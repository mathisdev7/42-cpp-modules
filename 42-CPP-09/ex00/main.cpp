/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:42:51 by mazeghou          #+#    #+#             */
/*   Updated: 2025/03/05 14:03:28 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Please send an input file\n./btc <filename>" << std::endl;
		return (0);
	}
	std::string fileName = argv[1];
	try
	{
		BitcoinExchange btc(fileName);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
