/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:29:52 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/18 19:35:52 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

class Weapon
{
private:
	std::string _type;

public:
	const std::string &getType(void) const;
	void setType(std::string type);
	Weapon(std::string type);
	~Weapon();
};
