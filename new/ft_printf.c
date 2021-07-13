#include "ft_printf.h"

int	ft_printf_char(char f)
{
	write(1, &f, 1);
	return (1);
}

int	check_flags(va_list args, const char *fmt, int *i)
{
	(*i)++;
	if (fmt[*i] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else if (fmt[*i] == 'c')
	{
		ft_printf_char(va_arg(args, int));
		(*i)++;
	}
	return (0);
}
int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		printed;
	int		i;

	va_start(args, fmt);
	printed = 0;
	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
			printed += check_flags(args, fmt, &i);
		else
		{
			write(1, &fmt[i], 1);
			i++;
			printed++;
		}
	}
	va_end(args);
	return (printed);
}
