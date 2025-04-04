/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:03:04 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/27 15:17:48 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
	std::cout << "Default Constructor called" << std::endl;
}

void Span::addNumber(int number)
{
	if (_values.size() >= _N)
		throw Span::SpanFullException();
	_values.push_back(number);
}

int Span::longestSpan() const
{
	if (_values.size() < 2)
		throw Span::NotEnoughNumbersException();

	return (*std::max_element(_values.begin(), _values.end()) -
			*std::min_element(_values.begin(), _values.end()));
}

int Span::shortestSpan() const
{
	if (_values.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> sorted = _values;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; ++i)
	{
		minSpan = std::min(minSpan, sorted[i + 1] - sorted[i]);
	}

	return minSpan;
}

Span::Span(const Span &other) : _N(other._N), _values(other._values)
{
	std::cout << "Copy Constructor called" << std::endl;
}

Span::~Span()
{
	std::cout << "Default Destructor called" << std::endl;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_values = other._values;
	}
	return (*this);
}

const char *Span::SpanFullException::what() const throw()
{
	return "Span is already full of numbers.";
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return "Span does not have enough numbers.";
}
