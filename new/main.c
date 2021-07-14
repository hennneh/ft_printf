#include <stdio.h>

int     ft_printf(const char *fmt, ...);

int	main(void)
{
	char	*d = "hello world";
	char	c = 'a';

	ft_printf("character: %c\n", c);
	ft_printf("string: %s\n", d);
	return (0);
}
