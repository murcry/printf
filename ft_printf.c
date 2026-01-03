/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 00:44:53 by digonza2          #+#    #+#             */
/*   Updated: 2026/01/03 19:53:02 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief
 * 
 * @param s
 * @return
 */
int	ft_print_str(const char *s)
{
	int	i;
	int	len;

	if (!s)
		return (ft_null());
	i = -1;
	len = 0;
	while (s[++i])
		len += ft_print_char((int)s[i]);
	return (len);
}

/**
 * @brief
 * 
 * @param c
 * @return
 */
int	ft_print_char(const int c)
{
	write(1, (char *)&c, 1);
	return (1);
}

/**
 * @brief
 * 
 * @param args
 * @param c
 * @return
 */
int	ft_formats(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (c == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		len += ft_print_punt(va_arg(args, unsigned long long));
	else if (c == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		len += ft_print_int(va_arg(args, int));
	else if (c == 'u')
		len += ft_print_unsgint(va_arg(args, unsigned int));
	else if (c == 'x')
		len += ft_print_hex(va_arg(args, unsigned int));
	else if (c == 'X')
		len += ft_print_hexup(va_arg(args, unsigned int));
	else if (c == '%')
		len += ft_print_percent();
	return (len);
}

/**
 * @brief
 * 
 * @param str
 * @param ...
 * @return
 */
int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			len += ft_print_char(str[i]);
	}
	va_end(args);
	return (len);
}
