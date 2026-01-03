/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 00:38:29 by digonza2          #+#    #+#             */
/*   Updated: 2026/01/03 19:41:57 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_print_char(const int c);

int		ft_print_str(const char *s);

int		ft_putnbr_bs(unsigned long long n, const char *base);

int		ft_putnbr(int n);

int		ft_print_unsgint(const unsigned int n);

int		ft_print_punt(const unsigned long long n);

int		ft_print_hex(const unsigned int n);

int		ft_print_hexup(const unsigned int n);

int		ft_formats(va_list args, const char c);

int		ft_null(void);

int		ft_nil(void);

int		ft_putminint(void);

int		ft_print_percent(void);

size_t	ft_strlen(const char *s);

int		ft_printf(char const *str, ...);

#endif