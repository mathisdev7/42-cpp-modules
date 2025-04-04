/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:46:25 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/21 07:23:45 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "./Animal.hpp"
#include <string>

class Dog : public Animal
{
private:
	std::string _type;

public:
	Dog();
	Dog(Dog const &src);
	~Dog();
	std::string getType(void) const;
	void makeSound(void) const;
	Dog &operator=(Dog const &rhs);
};
