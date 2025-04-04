/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:44:42 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/21 08:02:04 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{

public:
	Animal();
	Animal(Animal const &src);
	virtual ~Animal();
	virtual std::string getType(void) const;
	virtual void makeSound(void) const;
	Animal &operator=(Animal const &rhs);

protected:
	std::string _type;
};
