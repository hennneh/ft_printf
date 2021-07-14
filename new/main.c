#include <stdio.h>

int     ft_printf(const char *fmt, ...);

int	main(void)
{
	char	*d = "hello world";
	ft_printf("string: %s\n", d);
	return (0);
}
