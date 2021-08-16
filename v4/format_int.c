#include "ft_printf.h"

static size_t	ft_len(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	format_int(va_list *arguments)
{
	int		target;

	target = va_arg(*arguments, int);
	ft_putnbr_fd(target, 1);
	target = ft_len((long)target);
	return (target);
}
