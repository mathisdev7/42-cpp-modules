/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:21:01 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/20 12:38:49 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

#pragma once

class ScavTrap : public ClapTrap
{
private:
	bool _guarding_gate;

public:
	ScavTrap();
	ScavTrap(const ScavTrap &src);
	ScavTrap(std::string name);
	virtual ~ScavTrap();
	ScavTrap &operator=(const ScavTrap &src);
	void attack(const std::string &target);
	void guardGate(void);
};
