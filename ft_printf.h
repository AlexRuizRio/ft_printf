/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:24:36 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/08/19 00:27:38 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h> 
# include "libft/libft.h"

int ft_printf(const char *format, ...);
static int conversions (const char ptr, va_list args);
int	ft_print_str(char *s);
int ft_print_char ( char c);
int ft_print_hexa (unsigned int num, const char format);

#endif