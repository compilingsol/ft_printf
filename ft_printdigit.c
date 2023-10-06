/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-sg <maria-sg@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:30:21 by maria-sg          #+#    #+#             */
/*   Updated: 2023/10/06 17:56:57 by maria-sg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdigit(long n, int base, int uppercase)
{
	int			value;
	const char	*symbols;

	value = 0;
	if (uppercase)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < 0)
	{
		value += write(1, "-", 1);
		value += ft_printdigit(-n, base, uppercase);
	}
	else if (n < base)
		return (value += write(1, &symbols[n], 1));
	else
	{
		value += ft_printdigit(n / base, base, uppercase);
		value += ft_printdigit(n % base, base, uppercase);
	}
	return (value);
}

// int main()
// {
// 	long	num = -545646896;

// 	printdigit(num, 16, 1); // Print as uppercase hexadecimal
// 	write(1, "\n", 1);
// 	printdigit(num, 16, 0); // Print as lowercase hexadecimal
// 	write(1, "\n", 1);
// 	printdigit(num, 10, 0); // Print as decimal
// 	return (0);
// }

// int	printdigit(long n, int base, int uppercase)
// {
// 	int			value;
// 	const char	*symbols;

// 	value = 0;
// 	if (uppercase)
// 		symbols = "0123456789ABCDEF";
// 	else
// 		symbols = "0123456789abcdef";
// 	if (n < 0)
// 	{
// 		value += write(1, "-", 1);
		//calls itself to make the number positive
// 		value += printdigit(-n, base, uppercase);
// 	}
// 	else if (n < base)
		//writes the corresponding symbol and increments value
		//by the number of characters written
// 		return (value += write(1, &symbols[n], 1));
// 	else
// 	{
		//calls itself recursively with n / base
		//(the quotient of n divided by base)
		//then with n % base (the remainder of n divided by base).
		//This is how it handles numbers with more than
		//one digit in the specified base.
// 		value += printdigit(n / base, base, uppercase);
// 		value += printdigit(n % base, base, uppercase);
// 	}
// 	return (value);
// }