/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:21:01 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/20 13:01:19 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

#pragma once

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(const FragTrap &src);
	FragTrap(std::string name);
	virtual ~FragTrap();
	FragTrap &operator=(const FragTrap &src);
	void highFiveGuys(void);
};
