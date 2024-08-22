/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:44:07 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/08/22 16:58:37 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_pointer(uintptr_t num);
static void	ft_put_pointer(uintptr_t num);

int	ft_print_pointer(void *p)
{
	uintptr_t	pointer;
	int			len;
	
	if (p == NULL)
		return (ft_print_str("(nil)"));
	pointer = (uintptr_t)p;
	len = write(1, "0x", 2);
	if (pointer == 0)
		len += write(1, "0", 1);
	else
	{
		ft_put_pointer(pointer);
		len += ft_len_pointer(pointer);
	}
	return (len);
}

static int	ft_len_pointer(uintptr_t num)
{
	int	len;

	len = 0;
	while (num)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static void	ft_put_pointer(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_pointer(num / 16);
		ft_put_pointer(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_print_char(num + '0');
		else
			ft_print_char(num - 10 + 'a');
	}
}
