/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 07:01:48 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/21 08:00:31 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Dog dog;
	Cat cat;

	Dog &dog_ref = dog;
	Cat &cat_ref = cat;

	std::cout << std::endl
			  << "creating copies" << std::endl;
	Dog dog_copy(dog_ref);
	Cat cat_copy(cat_ref);

	Dog &dog_copy_ref = dog_copy;
	Cat &cat_copy_ref = cat_copy;

	std::cout << std::endl
			  << "comparing" << std::endl;
	dog.dogCompare(dog_copy_ref);
	cat.catCompare(cat_copy_ref);
	std::cout << std::endl;

	const Animal *animal_array[4];
	std::cout << std::endl;
	for (int i = 0; i < 2; i++)
		animal_array[i] = new Dog();
	std::cout << std::endl;
	for (int i = 2; i < 4; i++)
		animal_array[i] = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animal_array[i];
	std::cout << std::endl;
}
