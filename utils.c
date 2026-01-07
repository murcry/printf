/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:25:27 by digonza2          #+#    #+#             */
/*   Updated: 2026/01/07 20:28:26 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Computes the length of the string s.
 *
 * @param s The string to measure.
 * @return The number of characters that precede the terminating NUL character.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * @brief Print the string "(null)" for null strings.
 * 
 * @return 6.
 */
int	ft_null(void)
{
	write(1, "(null)", 6);
	return (6);
}

/**
 * @brief Print the string "(nil)" for null pointers.
 * 
 * @return 5.
 */
int	ft_nil(void)
{
	write(1, "(nil)", 5);
	return (5);
}

/**
 * @brief Print the "%" char.
 * 
 * @return 1.
 */
int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

/**
 * @brief Print the INT_MIN "-2147483648" (for int) string.
 * 
 * @return 11.
 */
int	ft_putminint(void)
{
	write(1, "-2147483648", 11);
	return (11);
}
