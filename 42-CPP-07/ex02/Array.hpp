/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:32:29 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/26 15:35:24 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;

public:
	Array() : _array(NULL), _size(0) {}

	Array(unsigned int n) : _size(n)
	{
		_array = new T[n]();
	}

	Array(const Array &other) : _size(other._size)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}

	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] _array;
			_size = other._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		return *this;
	}

	~Array()
	{
		delete[] _array;
	}

	T &operator[](unsigned int index)
	{
		if (index >= _size)
			throw std::exception();
		return _array[index];
	}

	unsigned int size() const
	{
		return _size;
	}
};
