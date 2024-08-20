/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:44:07 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/08/20 15:22:34 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_int(long num);
char		*ft_itoa(int n);

int	ft_print_int(int num)
{
	int		len;
	char	*result;

	result = ft_itoa(num);
	len = ft_print_str(result);
	free(result);
	return (len);
}

static int	len_int(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len++;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	len;
	long	num;

	num = n;
	len = len_int(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		num = -num;
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		while (len-- > 0)
		{
			str[len] = (num % 10) + '0';
			num = num / 10;
		}
		if (n < 0)
			str[0] = '-';
	}
	return (str);
}
