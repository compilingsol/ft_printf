/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-sg <maria-sg@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:03:09 by maria-sg          #+#    #+#             */
/*   Updated: 2023/10/06 17:50:09 by maria-sg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_putptr(uintptr_t num)
{
	char	*symbols;
	int		value;

	value = 0;
	symbols = "0123456789abcdef";
	if (num >= 16)
	{
		value += ft_putptr(num / 16);
		value += ft_putptr(num % 16);
	}
	else
		value += write(1, &symbols[num], 1);
	return (value);
}

int	ft_printpointer(unsigned long long ptr)
{
	int	value;

	value = 0;
	if (!ptr)
		value += write(1, "(nil)", 5);
	else
	{
		value += ft_printstr("0x");
		value += ft_putptr(ptr);
	}
	return (value);
}
