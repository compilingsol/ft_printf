
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
 
 int(?) printarg(va_list arg, char c, size_t i) //por que seria un int? puede ser otra cosa? por que?
 {
 	va_start char;
  
    if (c == 'c')
        ft_putchar_fd();
    if (c == 's')
        ft_putstr_fd();
    if (c == 'd')
        ft_putnbr_fd();
    if (c == 'i')
        ft_itoa();
    if (c == 'p')
        ft_putpointer();
    if (c == 'u')
        ft_putundec();
    if (c == 'x')
        ft_lowhex();
    if (c == 'X')
        ft_upphex();
    if (c == '%')
        ft_putperc();
    
    return (0);


 }






int ft_printf(const char *str, ...)
{
    va_list arg;
    size_t  i;

    va_start(arg, s);
    i = 0;
    while (*str)
    {
        if (str[i] == '%')
        {
            /* code */
        }
        
    }
    



    size_t len;

    len = ft_strlen(str);

    printarg(va_?, c)
    
    return (len);
    
}