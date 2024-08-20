/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:42:45 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/08/20 12:35:15 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_unsigned(long num);
static char *ft_itoa_unsig(unsigned int num);

int	ft_print_unsigned(unsigned int num)
{
    int		len;
    char	*result;
	
	len = 0;
	if  (num == 0)
		len = write (1, "0", 1);
	else
	{
		result = ft_itoa_unsig(num);
		len = ft_print_str(result);
		free(result);
	}
	return (len);
}

static int	len_unsigned(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static char *ft_itoa_unsig(unsigned int num)
{
	char	*str;
	long	len;

	len = len_unsigned(num);
	str = malloc(sizeof(char) * len + 1);
	if(!str)
		return (NULL);
	if (len == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num != 0)
	{
		--len;
		str[len] = (num % 10) + '0';
		num = num / 10;	
	}
	return (str);
}