/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 00:44:53 by digonza2          #+#    #+#             */
/*   Updated: 2025/12/29 01:03:51 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char const *str)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (str[++i])
	{
		write(1, &str[i], 1);
		len++;
	}
	return len;
}

/**
 * 
 */
// int	ft_printf(char const *str, ...)
// {
// 	va_list	args;
// 	int		i;
// 	int		len;

// 	i = -1;
// 	len = 0;
// 	va_start(args, str);
// 	while (str[++i])
// 	{
// 		// if (str[i] == '%')
// 		// 	len += ft_formats(args, str[i + 1]);
// 		// else
// 			len += ft_print_char(str[i]);
// 	}
// 	va_end(args);
// 	return(len);
// }
