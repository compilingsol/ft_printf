/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-sg <maria-sg@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:51:22 by maria-sg          #+#    #+#             */
/*   Updated: 2023/09/28 17:17:43 by maria-sg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

// Funciones globales extra:
// ft_putchar_fd.c Imprime caracter %c
// ft_putstr_fd.c Imprime string %s
// ft_putnbr_fd.c (creo que se llama asi) Imprime num %d
// ft_itoa.c De int a char %i

// 	-- hay que hacer:
//   • %p The void * pointer argument has to be printed in hexadecimal format
//   • %u Prints an unsigned decimal (base 10) number
//   • %x Prints a number in hexadecimal (base 16) lowercase format.
// 	• %X Prints a number in hexadecimal (base 16) uppercase format.
// 	• %% Prints a percent sign.


// Funciones estaticas extra:

// 1. Para escanear todos los argumentos. Lleno de if-else
//  aca se usa va arg?
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n > 9)
			ft_putnbr(n / 10);
		write(1, &"0123456789"[n % 10], 1);
	}
}
 
 int	printarg(va_list args, char c) //por que seria un int? puede ser otra cosa? por que?
 {
 	int	chars;

	chars = 0;  
    if (c == 'c')
        ft_putchar(va_arg(args, int));
    else if (c == 's')
        ft_putstr(va_arg(args, char *));
    else if (c == 'd')
        ft_putnbr(va_arg(args, int));
    else if (c == 'i')
        ft_putnbr(va_arg(args, int));
    else if (c == 'p')
        ft_putpointer(va_arg(args, uintprt_t));
    else if (c == 'u')
        ft_putundec(va_arg(args, unsigned int));
    else if (c == 'x')
        ft_lowhex(va_arg(args, int));
    else if (c == 'X')
        ft_upphex(va_arg(args, int));
    else if (c == '%')
        ft_putchar('%');
    
    return (chars);
 }

int ft_printf(const char *str, ...)
{
    va_list args;
    size_t  i;
	size_t	chars;

    va_start(args, str);
    i = 0;
	chars = 0;
    while (str[i] != '/0')
    {
        if (str[i] == '%')
        {
            chars = chars + printarg(args, str[i + 1]);
			i++;
        }
		else
		{
			chars = chars + printarg(str[i]);
		}
		i++;
	}
	va_end(args);
	return (chars);    
}
