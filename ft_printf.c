/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:24:51 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/08/04 12:40:08 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int conversions (const char *format, va_list args);

int ft_printf(const char *format, ...)
{
    va_list args;
    const char *ptr = format;
    int nbytes;

    va_start(args, format);
     while (*ptr)
    {
        if (*ptr == '%' && *(ptr + 1))
        {
            ptr++;
            nbytes += conversions (ptr, args);
        }
        else
        {
            ft_putchar_fd(*ptr, 1); // tiene que devolver un int
        }
        ptr++;
    }
    return (nbytes);
    va_end(args);
}


static int conversions (const char ptr, va_list args)
{
    if(ptr == '%')
        return(0);
    else if (ptr == 'c')
        return (0);
    else if (ptr == 's')
        return (0);
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

int main()
{
    ft_putchar_fd('a', 1);
    ft_putchar_fd('\n', 1);
    int printtf = ft_printf("Estoy probando %d asi que %d esperar \n", 10, 30);

    int print = printf("Estoy probando %d asi que %d esperar \n", 10, 30);

    printf("el numero en print es %d y el numero en printf es %d \n", print, printtf);
    return (0);
}
