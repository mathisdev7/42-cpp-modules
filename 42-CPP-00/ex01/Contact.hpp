/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:05:03 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/18 19:30:37 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>

class Contact
{
public:
	Contact(void);
	~Contact(void);
	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickname(void);
	std::string getDarkestSecret(void);
	std::string getPhone(void);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickname(std::string nickname);
	void setDarkestSecret(std::string darketSecret);
	void setPhone(std::string phone);

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string darkestSecret;
	std::string phone;
};

#endif
