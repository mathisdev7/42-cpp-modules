/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:58:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/26 11:25:16 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <cstdlib>
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter() : _input(""), _type(0), _char(0), _int(0), _float(0.0f), _double(0.0), _impossible(false)
{
	std::cout << "ScalarConverter Default Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string input) : _input(input), _type(0), _char(0), _int(0), _float(0.0f), _double(0.0), _impossible(false)
{
	std::cout << "ScalarConverter Constructor for " << this->getInput() << std::endl;
	this->convertInput();
	this->printOutput();
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) : _input(src.getInput()), _type(0), _char(0), _int(0), _float(0.0f), _double(0.0), _impossible(false)
{
	std::cout << "ScalarConverter Copy Constructor called" << std::endl;
	*this = src;
	this->printOutput();
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	std::cout << "ScalarConverter Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src.getType();
	this->_char = src.getChar();
	this->_int = src.getInt();
	this->_float = src.getFloat();
	this->_double = src.getDouble();
	this->_impossible = src._impossible;
	return *this;
}

void ScalarConverter::printOutput(void) const
{
	std::cout << "char: ";
	if (_impossible || std::isnan(_double) || std::isinf(_double) || _double < 0 || _double > 127)
		std::cout << "impossible";
	else if (_double < 32 || _double > 126)
		std::cout << "Non displayable";
	else
		std::cout << "'" << _char << "'";
	std::cout << std::endl;

	std::cout << "int: ";
	if (_impossible || std::isnan(_double) || std::isinf(_double) ||
		_double > std::numeric_limits<int>::max() || _double < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << _int;
	std::cout << std::endl;

	std::cout << "float: ";
	if (std::isnan(_double))
		std::cout << "nanf";
	else if (std::isinf(_double))
		std::cout << (_double < 0 ? "-" : "+") << "inff";
	else
	{
		std::cout << _float;
		if (_float == static_cast<int>(_float))
			std::cout << ".0";
		std::cout << "f";
	}
	std::cout << std::endl;

	std::cout << "double: ";
	if (std::isnan(_double))
		std::cout << "nan";
	else if (std::isinf(_double))
		std::cout << (_double < 0 ? "-" : "+") << "inf";
	else if (_impossible)
		std::cout << "impossible";
	else
	{
		std::cout << _double;
		if (_double == static_cast<int>(_double))
			std::cout << ".0";
	}
	std::cout << std::endl;
}

void ScalarConverter::convertInput(void)
{
	_type = checkInput();
	switch (_type)
	{
	case 0:
		fromChar();
		break;
	case 1:
		fromInt();
		break;
	case 2:
		fromFloat();
		break;
	case 3:
		fromDouble();
		break;
	default:
		throw std::runtime_error("Invalid input type");
	}
}

int ScalarConverter::checkInput(void)
{
	if (_input.empty())
		throw std::runtime_error("Empty input");

	if (_input.length() == 1 && !std::isdigit(_input[0]))
		return 0;

	if (_input == "nan" || _input == "nanf")
	{
		_type = 2;
		_double = std::numeric_limits<double>::quiet_NaN();
		_float = std::numeric_limits<float>::quiet_NaN();
		_int = 0;
		_char = 0;
		_impossible = true;
		return _type;
	}

	if (_input == "+inf" || _input == "inf" || _input == "+inff" || _input == "inff")
	{
		_type = 2;
		_double = std::numeric_limits<double>::infinity();
		_float = std::numeric_limits<float>::infinity();
		_int = 0;
		_char = 0;
		_impossible = true;
		return _type;
	}

	if (_input == "-inf" || _input == "-inff")
	{
		_type = 2;
		_double = -std::numeric_limits<double>::infinity();
		_float = -std::numeric_limits<float>::infinity();
		_int = 0;
		_char = 0;
		_impossible = true;
		return _type;
	}

	bool hasDecimal = false;
	bool hasF = false;
	size_t start = 0;

	if (_input[0] == '-' || _input[0] == '+')
		start = 1;

	if (start == _input.length())
		throw std::runtime_error("Invalid input: only sign");

	for (size_t i = start; i < _input.length(); i++)
	{
		if (_input[i] == '.')
		{
			if (hasDecimal)
				throw std::runtime_error("Invalid number format: multiple decimal points");
			hasDecimal = true;
		}
		else if (_input[i] == 'f' && i == _input.length() - 1)
			hasF = true;
		else if (!std::isdigit(_input[i]))
			throw std::runtime_error("Invalid character in number");
	}

	if (hasF && !hasDecimal)
		throw std::runtime_error("Invalid float format: missing decimal point");

	_type = hasF ? 2 : (hasDecimal ? 3 : 1);
	return _type;
}

void ScalarConverter::fromChar(void)
{
	_char = _input[0];
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}

void ScalarConverter::fromInt(void)
{
	_int = std::atoi(_input.c_str());
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void ScalarConverter::fromFloat(void)
{
	_float = std::atof(_input.c_str());
	_int = static_cast<int>(_float);
	_char = static_cast<char>(_float);
	_double = static_cast<double>(_float);
}

void ScalarConverter::fromDouble(void)
{
	_double = std::strtod(_input.c_str(), NULL);
	_int = static_cast<int>(_double);
	_char = static_cast<char>(_double);
	_float = static_cast<float>(_double);
}

std::string ScalarConverter::getInput(void) const
{
	return this->_input;
}

int ScalarConverter::getType(void) const
{
	return this->_type;
}

char ScalarConverter::getChar(void) const
{
	return this->_char;
}

int ScalarConverter::getInt(void) const
{
	return this->_int;
}

float ScalarConverter::getFloat(void) const
{
	return this->_float;
}

double ScalarConverter::getDouble(void) const
{
	return this->_double;
}
