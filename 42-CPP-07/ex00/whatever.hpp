/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:09:51 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/26 15:16:48 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#pragma once

template <typename T>
T &max(T x, T y)
{
	return (x >= y) ? x : y;
}

template <typename Y>
Y &min(Y x, Y y)
{
	return (x >= y) ? y : x;
}

template <typename U>
void swap(U &x, U &y)
{
	U temp = x;
	x = y;
	y = temp;
}
