/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:56:27 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/26 11:14:15 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>

class ScalarConverter
{
private:
	const std::string _input;
	int _type;
	char _char;
	int _int;
	float _float;
	double _double;
	bool _impossible;
	ScalarConverter();
	int checkInput(void);
	void convertInput(void);

	void fromChar(void);
	void fromInt(void);
	void fromFloat(void);
	void fromDouble(void);

	void printOutput(void) const;

	std::string getInput(void) const;
	int getType(void) const;
	char getChar(void) const;
	int getInt(void) const;
	float getFloat(void) const;
	double getDouble(void) const;

public:
	ScalarConverter(const std::string input);
	ScalarConverter(const ScalarConverter &src);

	~ScalarConverter();

	ScalarConverter &operator=(const ScalarConverter &src);
};
