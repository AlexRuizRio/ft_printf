/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:24:51 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/08/19 00:47:12 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int conversions (const char ptr, va_list args);
int ft_putchar (char c);
int ft_strlens (const char *str);
int	ft_putstr(char *s);
static void ft_put_hexa (unsigned int num, const char format);

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
        return (ft_print_hexa(va_arg(args, unsigned int), ptr));
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

int ft_print_hexa (unsigned int num, const char format)
{
    int len;
    if (num == 0)
    {
        return(write(1, "0", 1));
        return(1);
    }
    len = 0;
    ft_put_hexa(num, format);
    while(num)
    {
        num = num / 16;
        len++;
    }
    return (len);
}

static void ft_put_hexa (unsigned int num, const char format)
{
    if (num >= 16)
    {
        ft_put_hexa (num / 16, format);
        ft_put_hexa (num % 16, format);
    }
    else
    {
        if(num <= 9)
            ft_print_char(num + '0');
        else
        {
            if(format == 'X')
                ft_print_char(num - 10 + 'A');
            if(format == 'x')
                ft_print_char(num - 10 + 'a');
        }
    }
}

int main()
{
    ft_print_char('a');
    ft_printf("holi \n");
    char *str = "estamos probando";
    int printtfi = ft_printf("Estoy probando %c asi que %c esperar \n", 'a', 'a');
    int printi = printf("Estoy probando %c asi que %c esperar \n", 'a', 'a');

    int printtf = ft_printf("Hola %s \n", str);
    int print = printf("Hola %s \n", str);

    int printfper = ft_printf("Imprimiendo un porcentaje:%% \n");
    int printper = printf("Imprimiendo un porcentaje:%% \n");

    int printfhex = ft_printf("Imprimiendo un numero hex: %x \n", 0);
    int printhex = printf("Imprimiendo un numero hex: %x \n", 0);

    printf("PORCENTAJE: el numero en print es %d y el numero en printf es %d \n", printper, printfper);
    printf("STRING: el numero en print es %d y el numero en printf es %d \n", print, printtf);
    printf("CHAR: el numero en print es %d y el numero en printf es %d \n", printi, printtfi);
    printf("HEXADECIMAL: el numero en print es %d y el numero en printf es %d \n", printhex, printfhex);
    return (0);
}
