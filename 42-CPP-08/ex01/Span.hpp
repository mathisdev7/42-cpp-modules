/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:57:26 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/27 15:16:53 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
	unsigned int _N;
	std::vector<int> _values;

public:
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void addNumber(int number);
	template <typename InputIterator>
	void addNumbers(InputIterator begin, InputIterator end)
	{
		if (_values.size() + std::distance(begin, end) > _N)
			throw SpanFullException();
		_values.insert(_values.end(), begin, end);
	}
	int longestSpan() const;
	int shortestSpan() const;
	class SpanFullException : public std::exception
	{
		const char *what() const throw();
	};
	class NotEnoughNumbersException : public std::exception
	{
		const char *what() const throw();
	};
};
