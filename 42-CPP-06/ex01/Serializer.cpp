/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:27:02 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/26 11:33:40 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "Copy Constructor called" << std::endl;
	(void)src;
}

Serializer::~Serializer()
{
	std::cout << "Default Destructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	(void)src;
	std::cout << "Copy Constructor called" << std::endl;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
