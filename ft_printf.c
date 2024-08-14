/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:24:51 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/08/14 12:56:47 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int conversions (const char ptr, va_list args);
int ft_putchar (char c);
int ft_strlens (const char *str);
int	ft_putstr(char *s);

int ft_printf(const char *format, ...)
{
    va_list args;
    const char *ptr = format;
    int nbytes;

    va_start(args, format);
    nbytes = 0;
     while (*ptr)
    {
        if (*ptr == '%' && *(ptr + 1))
        {
            ptr++;
            nbytes += conversions (*ptr, args);
        }
        else
        {
            nbytes += ft_print_char(*ptr); // tiene que devolver un int
        }
        ptr++;
    }
    va_end(args);
    return (nbytes);

}

static int conversions (const char ptr, va_list args)
{
    if(ptr == '%')
        return(ft_print_char('%'));
    else if (ptr == 'c')
        return (ft_print_char(va_arg(args, int)));
    else if (ptr == 's')
        return (ft_print_str(va_arg(args, char *)));
    else if (ptr == 'p')
        return (0);
    else if (ptr == 'd' || ptr == 'i')
        return (0);
    else if (ptr == 'u')
        return (0);
    else if (ptr == 'x' || ptr == 'X')
        return (0);
    return (0);
}
int	ft_print_str(char *s)
{
	int	len;

    len = 0;
    if(s == NULL)
    {
        return (ft_print_str("(null)"));
    }
	len = ft_strlens(s);
	write(1, s, len);
    return (len);
}

int ft_print_char ( char c)
{
    return(write(1, &c, 1));
}

int ft_strlens (const char *str)
{
    int len;
    
    if(str == NULL)
        return (0);
    len = 0;
    while(*str)
    {
        len++;
        str++;
    }
     return (len);
    
}
int main()
{
    ft_print_char('a');
    ft_print_char('\n');
    char *str = "estamos probando";
    int printtfi = ft_printf("Estoy probando %c asi que %c esperar \n", 'a', 'a');
    int printi = printf("Estoy probando %c asi que %c esperar \n", 'a', 'a');

    int printtf = ft_printf("Hola %s \n", str);
    int print = printf("Hola %s \n", str);

    int printfper = ft_printf("Imprimiendo un porcentaje:%% \n");
    int printper = printf("Imprimiendo un porcentaje:%% \n");

    printf("PORCENTAJE: el numero en print es %d y el numero en printf es %d \n", printper, printfper);
    printf("STRING: el numero en print es %d y el numero en printf es %d \n", print, printtf);
    printf("CHAT: el numero en print es %d y el numero en printf es %d \n", printi, printtfi);
    return (0);
}
