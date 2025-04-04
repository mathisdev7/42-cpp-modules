/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:45:59 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/21 07:52:08 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "./Animal.hpp"
#include "./Brain.hpp"
#include <string>

class Cat : public Animal
{
private:
	std::string _type;
	Brain *_brain;

public:
	Cat();
	Cat(Cat &src);
	~Cat();
	std::string getType(void) const;
	void catCompare(Cat const &other_cat) const;
	Brain *getBrain(void) const;
	void makeSound(void) const;
	Cat &operator=(Cat const &rhs);
};
