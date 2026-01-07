/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:36:41 by digonza2          #+#    #+#             */
/*   Updated: 2026/01/07 16:51:24 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	len_mio;
	int	len_orig;

	printf("--- TEST STRING ---\n");
	len_mio = ft_printf("Mio: Hola %s\n", "Mundo");
	len_orig = printf("Org: Hola %s\n", "Mundo");
	printf("Len Mio: %d | Len Orig: %d\n\n", len_mio, len_orig);
	printf("--- TEST NUMEROS ---\n");
	len_mio = ft_printf("Mio: %d, %i, %u\n", -42, 42, -1);
	len_orig = printf("Org: %d, %i, %u\n", -42, 42, -1);
	printf("Len Mio: %d | Len Orig: %d\n\n", len_mio, len_orig);
	printf("--- TEST HEX & PTR ---\n");
	len_mio = ft_printf("Mio: %x %X %p\n", -42, -6434, &len_mio);
	len_orig = printf("Org: %x %X %p\n", -42, -6434, &len_mio);
	printf("Len Mio: %d | Len Orig: %d\n", len_mio, len_orig);
	return (0);
}
