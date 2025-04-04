/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:50:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/26 11:58:39 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "Testing random generation and identification:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "\nTest " << i + 1 << ":" << std::endl;

		Base *instance = generate();

		std::cout << "Identifying through pointer:" << std::endl;
		identify(instance);

		std::cout << "Identifying through reference:" << std::endl;
		identify(*instance);

		delete instance;
	}

	return 0;
}
