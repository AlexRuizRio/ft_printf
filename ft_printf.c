/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:24:51 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/08/20 12:41:02 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putchar(char c);
int			ft_strlens(const char *str);
int			ft_putstr(char *s);
static void	ft_put_hexa(unsigned int num, const char format);
static int	len_int(long num);
char	    *ft_itoa(int n);
static int	len_unsigned(long num);
static char *ft_itoa_unsig(unsigned int num);

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
static int	ft_len_pointer(uintptr_t num)
{
	int	len;

	len	= 0;
	while (num)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static void ft_put_pointer(uintptr_t num)
{
	if(num >= 16)
	{
		ft_put_pointer(num / 16);
		ft_put_pointer(num % 16);
	}
	else
	{
		if(num <= 9)
            ft_print_char(num + '0');
        else
            ft_print_char(num - 10 + 'a');

	}
}

int ft_print_pointer (void *p)
{
    int len;
    uintptr_t pointer;

    pointer = (uintptr_t)p;
    len = write(1,"0x",2);
    if (pointer == 0)
        len = write(1, "0",1);
    else
    {
		ft_put_pointer(pointer);
		len += ft_len_pointer(pointer);
    }
    return (len);
}

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

char *ft_itoa(int n)
{
    char *str;
    long len;
    long num;

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

int main()
{
    ft_print_char('a');
    ft_print_char('\n');
    ft_printf("Esto es una prueba \n");
    printf("Esto es una prueba \n");
    int intprintf = printf("esto es una prueba %d \n", -2147483647);
    int intftprintf = ft_printf("esto es una prueba %d \n", -2147483647);
    char *str = "estamos probando";
    int printtfi = ft_printf("Estoy probando %c asi que %c esperar \n", 'a', 'a');
    int printi = printf("Estoy probando %c asi que %c esperar \n", 'a', 'a');

    int printtf = ft_printf("Hola %s \n", str);
    int print = printf("Hola %s \n", str);

    int printfper = ft_printf("Imprimiendo un porcentaje:%% \n");
    int printper = printf("Imprimiendo un porcentaje:%% \n");

    int printfhex = ft_printf("Imprimiendo un numero hex: %X \n", 2024);
    int printhex = printf("Imprimiendo un numero hex: %X \n", 2024);
    
    int printfput = ft_printf("Imprimiendo un puntero: %p \n", str);
    int printput = printf("Imprimiendo un puntero: %p \n", str);

    int printfu = ft_printf("Imprimiendo un numero unsigned: %u \n", -2024);
    int printu = printf("Imprimiendo un numero unsigned: %u \n", -2024);
    
    ft_printf("INTEGER: el numero en printf es %d y el numero en ft_printf es %d \n", intprintf, intftprintf);
    ft_printf("PORCENTAJE: el numero en printf es %d y el numero en ft_printf es %d \n", printper, printfper);
    ft_printf("STRING: el numero en printf es %d y el numero en ft_printf es %d \n", print, printtf);
    ft_printf("CHAR: el numero en printf es %d y el numero en ft_printf es %d \n", printi, printtfi);
    ft_printf("HEXADECIMAL: el numero en printf es %d y el numero en ft_printf es %d \n", printhex, printfhex);
	ft_printf("PUNTERO: el numero en printf es %d y el numero en ft_printf es %d \n", printput, printfput);
    ft_printf("UNSIGNED: el numero en printf es %d y el numero en ft_printf es %d \n", printu, printfu);
    return (0);
}
