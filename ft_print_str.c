/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:42:45 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/08/14 12:45:33 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
