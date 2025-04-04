/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:45:59 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/21 07:24:32 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "./WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
protected:
	std::string _type;

public:
	WrongCat();
	WrongCat(WrongCat const &src);
	~WrongCat();
	std::string getType(void) const;
	void makeSound(void) const;
	WrongCat &operator=(WrongCat const &rhs);
};
