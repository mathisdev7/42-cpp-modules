/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:46:18 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/27 14:56:24 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class NotFoundException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Element not found in the container.";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int number)
{
	typename T::iterator it = std::find(container.begin(), container.end(), number);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}
