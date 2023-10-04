/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-sg <maria-sg@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:03:09 by maria-sg          #+#    #+#             */
/*   Updated: 2023/10/04 18:11:52 by maria-sg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printpointer(uintptr_t ptr)
{
	int	value;
	
	value = 0;
	if (ptr == 0)
		value += ft_printstr("nil");
	else
	{
		value += ft_printstr("0x");
		value += ft_printdigit(ptr, 16, 0);
	}
	return (value);
}