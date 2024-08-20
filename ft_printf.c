/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:24:51 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/08/20 15:21:06 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversions(const char ptr, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			nbytes;
	const char	*ptr;

	va_start(args, format);
	nbytes = 0;
	ptr = format;
	while (*ptr)
	{
		if (*ptr == '%' && *(ptr + 1))
		{
			ptr++;
			nbytes += conversions(*ptr, args);
		}
		else
		{
			nbytes += ft_print_char(*ptr);
		}
		ptr++;
	}
	va_end(args);
	return (nbytes);
}

static int	conversions(const char ptr, va_list args)
{
	if (ptr == '%')
		return (ft_print_char('%'));
	else if (ptr == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (ptr == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (ptr == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (ptr == 'd' || ptr == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (ptr == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (ptr == 'x' || ptr == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), ptr));
	return (0);
}
