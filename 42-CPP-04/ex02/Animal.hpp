/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:44:42 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/21 08:05:02 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string _type;

public:
	Animal();
	Animal(Animal const &src);
	virtual ~Animal() = 0;
	virtual std::string getType(void) const;
	virtual void makeSound(void) const = 0;
	Animal &operator=(Animal const &rhs);
};
