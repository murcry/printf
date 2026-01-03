/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:25:27 by digonza2          #+#    #+#             */
/*   Updated: 2026/01/03 19:45:20 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief
 * 
 * @return
 */
int	ft_null(void)
{
	write(1, "(null)", 6);
	return (6);
}

/**
 * @brief
 * 
 * @return
 */
int	ft_nil(void)
{
	write(1, "(nil)", 5);
	return (5);
}

/**
 * @brief
 * 
 * @return
 */
int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putminint(void)
{
	write(1, "-2147483648", 11);
	return (11);
}
