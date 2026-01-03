/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 00:44:53 by digonza2          #+#    #+#             */
/*   Updated: 2025/12/30 19:50:00 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief
 * 
 * @param
 * @return
 */
int	ft_print_str(char const *s)
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
 * @param
 * @return
 */
int	ft_print_char(int const c)
{
	write(1, (char *)&c, 1);
	return (1);
}

/**
 * @brief
 * 
 * @param
 * @param
 * @return
 */
int	ft_formats(va_list args, char const c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_print_char(va_arg(args, int));			//TODO
	else if (c == 's')
		len = ft_print_str(va_arg(args, char *));		//TODO
	// else if (c == 'p')
	// 	len = ft_print_punt();							//TODO
	// else if (c == 'd')
	// 	len = ft_print_double();						//TODO
	// else if (c == 'i')
	// 	len = ft_print_int();							//TODO
	// else if (c == 'u')
	// 	len = ft_print_unsgint();						//TODO
	// else if (c == 'x')
	// 	len = ft_print_hex();							//TODO
	// else if (c == 'X')
	// 	len = ft_print_hexup();							//TODO
	// else if (c == '%')
	// 	len = ft_print_percent();						//TODO
	return (len);
}

/**
 * @brief
 * 
 * @param
 * @param
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
