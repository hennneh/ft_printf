#include <stdio.h>

int     ft_printf(const char *fmt, ...);

int	main(void)
{
	char	d = 'b';
	ft_printf("character: %c\n", d);
	return (0);
}
