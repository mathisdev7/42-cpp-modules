/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:45:59 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/21 07:23:38 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "./Animal.hpp"
#include <string>

class Cat : public Animal
{
private:
	std::string _type;

public:
	Cat();
	Cat(Cat const &src);
	~Cat();
	std::string getType(void) const;
	void makeSound(void) const;
	Cat &operator=(Cat const &rhs);
};
