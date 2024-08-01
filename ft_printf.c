#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
    va_list args;
    int nbytes;
    
    va_start(args, format);
    
    return (nbytes);
}

int main()
{
    ft_putchar_fd('a', 1);
    ft_putchar_fd('\n', 1);
    printf("Estoy probando %d asi que %d esperar", 10, 30);
    return (0);
}