/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:01:38 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/18 19:31:55 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>

void PhoneBook::AddContact(void)
{
	std::string prompt;
	int temp_index;

	prompt = "";
	temp_index = 0;
	if (this->index == 8)
		std::cout << "Since there is more than 7 contacts, we will now overwrite the first." << std::endl;
	else
		temp_index = this->index;
	while (!std::cin.eof() && prompt == "")
	{
		std::cout << "Enter his/her first name: ";
		if (std::getline(std::cin, prompt) && prompt != "")
			this->contacts[temp_index].setFirstName(prompt);
	}
	prompt = "";
	while (!std::cin.eof() && prompt == "")
	{
		std::cout << "Enter his/her last name: ";
		if (std::getline(std::cin, prompt) && prompt != "")
			this->contacts[temp_index].setLastName(prompt);
	}
	prompt = "";
	while (!std::cin.eof() && prompt == "")
	{
		std::cout << "Enter his/her nickname: ";
		if (std::getline(std::cin, prompt) && prompt != "")
			this->contacts[temp_index].setNickname(prompt);
	}
	prompt = "";
	while (!std::cin.eof() && prompt == "")
	{
		std::cout << "Enter his/her darkest secret: ";
		if (std::getline(std::cin, prompt) && prompt != "")
			this->contacts[temp_index].setDarkestSecret(prompt);
	}
	prompt = "";
	while (!std::cin.eof() && prompt == "")
	{
		std::cout << "Enter his/her phone number: ";
		if (std::getline(std::cin, prompt) && prompt != "")
			this->contacts[temp_index].setPhone(prompt);
	}
	if (this->index < 8)
		this->index++;
}

void PhoneBook::PrintContact(Contact contact)
{
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
	std::cout << "Phone: " << contact.getPhone() << std::endl;
}

PhoneBook::PhoneBook(void)
{
	this->index = 0;
	std::cout << "Welcome to phonebook, register your friends as contacts" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Well, goodbye." << std::endl;
}

void PhoneBook::SearchContact()
{
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < this->index; i++)
	{
		if (contacts[i].getFirstName().empty())
			continue;
		std::string firstName = contacts[i].getFirstName();
		std::string lastName = contacts[i].getLastName();
		std::string nickname = contacts[i].getNickname();

		if (firstName.length() > 10)
		{
			firstName = firstName.substr(0, 9) + ".";
		}
		if (lastName.length() > 10)
		{
			lastName = lastName.substr(0, 9) + ".";
		}
		if (nickname.length() > 10)
		{
			nickname = nickname.substr(0, 9) + ".";
		}

		std::cout << "|" << std::setw(10) << std::right << i
				  << "|" << std::setw(10) << std::left << firstName
				  << "|" << std::setw(10) << std::left << lastName
				  << "|" << std::setw(10) << std::left << nickname << "|" << std::endl;
	}
	std::string input;
	std::cout << "Enter contact index (0-7): ";
	std::getline(std::cin, input);
	try
	{
		std::istringstream iss(input);
		int temp;
		if (!(iss >> temp))
		{
			std::cout << "Invalid index format." << std::endl;
			return;
		}
		if (temp < 0 || temp >= 8)
		{
			std::cout << "Invalid index range, must be between 0 and 8." << std::endl;
			return;
		}
		if (contacts[temp].getFirstName().empty())
		{
			std::cout << "Empty contact." << std::endl;
			return;
		}
		PrintContact(contacts[temp]);
	}
	catch (...)
	{
		std::cout << "Invalid index format." << std::endl;
	}
}
