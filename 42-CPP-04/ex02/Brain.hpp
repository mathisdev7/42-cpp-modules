/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 07:19:27 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/21 07:35:30 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain
{

public:
	Brain();
	Brain(Brain &src);
	~Brain();
	std::string *getIdeas(void);
	Brain &operator=(Brain const &rhs);

private:
	std::string _ideas[100];
};
