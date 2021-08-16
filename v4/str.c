#include "ft_printf.h"

int	format_str(va_list *arguments)
{
	char	*target;
	int		length;

	target = va_arg(*arguments, char *);
	if (target == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	length = ft_strlen(target);
	if (length == 0)
		return (0);
	ft_putstr_fd(target, 1);
	return (length);
}
