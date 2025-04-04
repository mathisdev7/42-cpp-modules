/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:34:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/26 11:34:50 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *originalData = new Data;
	originalData->value = 42;

	std::cout << "Original Data address: " << originalData << std::endl;
	std::cout << "Original Data value: " << originalData->value << std::endl;

	uintptr_t serialized = Serializer::serialize(originalData);
	std::cout << "Serialized value: " << serialized << std::endl;

	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized Data address: " << deserialized << std::endl;
	std::cout << "Deserialized Data value: " << deserialized->value << std::endl;

	std::cout << "\nVerification:" << std::endl;
	std::cout << "Are addresses equal? " << (originalData == deserialized ? "YES" : "NO") << std::endl;
	std::cout << "Are values equal? " << (originalData->value == deserialized->value ? "YES" : "NO") << std::endl;

	delete originalData;

	return 0;
}
