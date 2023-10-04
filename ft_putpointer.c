/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-sg <maria-sg@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:05:26 by maria-sg          #+#    #+#             */
/*   Updated: 2023/10/04 11:30:10 by maria-sg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



//calculates the length of the hexadecimal representation of the pointer.
int	ft_ptrlen(uintptr_t ptr)
{
	int	len;
	
	len = 0;
	while (ptr)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}



int	ft_putpointer(uintptr_t ptr)
{
	char	*pointer;
	int	len;
	
	if (ptr == 0)
	{
		ft_putstr("NULL"); //this might be wrong
		return (1);
	}
	pointer = ft_hexptrstr(ptr);
	len = ft_putstr("0x") + ft_putstr(pointer);
	free(pointer);
	return (len);
}

//converts the pointer value to a string of hexadecimal digits. 
// char	*ft_hexptrstr(uintptr_t ptr)
// {
	// char *str;
	// int	len;
	// int	store;

	// len = ft_ptrlen(ptr);
	// str = (char *)malloc((len + 1) * sizeof(char));
	// if (!str)
	// 	return (NULL);
	// str[len] = '\0';
	// len = len - 1;
	// while (len >= 0)
	// {
	// 	store = ptr % 16;
	// 	if (store < 10)
	// 		store = store + 48;
	// 	else
	// 		store = store + 87;
	// 	str[len--] = store;
	// 	ptr = ptr / 16;
	// }	
	// return (str);

	
	// int	len;
	// char	*str;
	// int	digit;

	// len = sizeof(ptr) * 2;
	// str = (char *)malloc((len +1) * sizeof(char));
	// if (!str)
	// 	return (NULL);
	// str[len] = 0;
	// len = len - 1;
	// while (len >= 0)
	// {
	// 	digit= ptr & 0xF;
	// 	if (digit < 10)
	// 		str[len] = '0' + digit;
	// 	else
	// 		str[len] = 'a' + digit - 10;
	// 	ptr >>= 4;
	// }
	// return (str);	
// }

// int	ft_putpointer(uintptr_t ptr)
// {
// 	char	*pointer;
// 	int	len;
	
// 	if (ptr == 0)
// 	{
// 		ft_putstr("NULL"); //this might be wrong
// 		return (1);
// 	}
// 	pointer = ft_hexptrstr(ptr);
// 	len = ft_putstr("0x") + ft_putstr(pointer);
// 	free(pointer);
// 	return (len);
// }
