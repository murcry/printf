/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:06:24 by digonza2          #+#    #+#             */
/*   Updated: 2026/01/07 17:14:43 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print an unsigned number in decimal base.
 * 
 * @param n The number we are printing.
 * @return The length of the text printed.
 */
int	ft_print_unsgint(const unsigned int n)
{
	return (ft_putnbr_bs(n, "0123456789"));
}

/**
 * @brief Print an any decimal based number (from INT_MIN to INT_MAX).
 * 
 * @param n The number we want to print.
 * @return The length of the text printed.
 */
int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == INT_MIN)
		return (ft_putminint());
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			len++;
			n *= -1;
		}
		if (n >= 10)
			len += ft_putnbr(n / 10);
		len += ft_putnbr_bs(n % 10, "0123456789");
	}
	return (len);
}
