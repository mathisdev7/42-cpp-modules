/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:09:51 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/26 15:29:19 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#pragma once

template <typename T>
void iter(T *arr, size_t length, void (*func)(T &))
{
	for (size_t i = 0; i < length; i++)
		func(arr[i]);
}
