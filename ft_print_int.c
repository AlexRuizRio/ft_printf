/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:44:07 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/08/19 17:24:00 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int (int num)
{
	int 	len;
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

	len = ft_intlen(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (n != 0 && n != -2147483648)
	{
		len--;
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (n < 0)
			str[len] = '-';
	return (str);
}