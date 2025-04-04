/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:18:19 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/18 19:35:52 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *str_ptr = &str;
	std::string &str_ref = str;

	(void)str_ptr;
	(void)str_ref;
	std::cout << "Memory address of str: " << &str << std::endl;
	std::cout << "Memory address of str_ptr: " << str_ptr << std::endl;
	std::cout << "Memory address of str_ref: " << &str_ref << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value pointed to by str_ptr: " << *str_ptr << std::endl;
	std::cout << "Value pointed to by str_ref: " << str_ref << std::endl;
}
