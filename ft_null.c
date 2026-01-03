/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:25:27 by digonza2          #+#    #+#             */
/*   Updated: 2025/12/30 19:50:04 by digonza2         ###   ########.fr       */
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
int	ft_nill(void)
{
	write(1, "(nill)", 6);
	return (6);
}