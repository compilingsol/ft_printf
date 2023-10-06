/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-sg <maria-sg@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:13 by maria-sg          #+#    #+#             */
/*   Updated: 2023/10/06 17:57:01 by maria-sg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printchar(char c);
int	ft_printdigit(long n, int base, int uppercase);
int	ft_printf(const char *str, ...);
int	ft_printpointer(unsigned long long ptr);
//int	print_pointer(unsigned long long ptr);
int	ft_printstr(char *str);

#endif