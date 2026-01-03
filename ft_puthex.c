/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:47:51 by digonza2          #+#    #+#             */
/*   Updated: 2026/01/02 13:02:57 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"

// char	*ft_putnbrbs(unsigned long long n, char *base)
// {

// }

// void	ft_putnbr_fd(int n, int fd)
// {
// 	if (n == INT_MIN)
// 		write(fd, "-2147483648", 11);
// 	else
// 	{
// 		if (n < 0)
// 		{
// 			write(fd, "-", 1);
// 			n *= -1;
// 		}
// 		if (n >= 10)
// 			ft_putnbr_fd(n / 10, fd);
// 		ft_putchar_fd((n % 10) + '0', fd);
// 	}
// }
