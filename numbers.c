/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:06:24 by digonza2          #+#    #+#             */
/*   Updated: 2026/01/07 20:12:47 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Prints any positive number in any base we want.
 * 
 * @param n The number (in decimal base) we want to print.
 * @param base The base we want for our printed number.
 * @return The length of the text printed.
 */
int	ft_putnbr_bs(const unsigned long long n, const char *base)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (n >= ft_strlen(base))
		len += ft_putnbr_bs(n / base_len, base);
	len += ft_print_char(base[n % base_len]);
	return (len);
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

/**
 * @brief Print the memory allocation for a variable (lowercase hex with
 * "0x" prefix).
 * 
 * @param n The position in memory.
 * @return The length of the text printed.
 */
int	ft_print_punt(const unsigned long long n)
{
	int					len;

	len = 0;
	if (n == 0)
		return (ft_nil());
	else
	{
		write(1, "0x", 2);
		len += 2;
		len += ft_putnbr_bs(n, "0123456789abcdef");
	}
	return (len);
}
