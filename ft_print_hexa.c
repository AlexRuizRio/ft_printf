/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:21:02 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/08/19 00:44:18 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_put_hexa (unsigned int num, const char format);

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