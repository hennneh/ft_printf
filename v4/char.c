#include "ft_printf.h"

int	format_char(va_list *arguments)
{
	char	target;

	target = va_arg(*arguments, int);
	ft_putchar_fd(target, 1);
	return (1);
}
