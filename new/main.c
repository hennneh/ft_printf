#include <stdio.h>

int     ft_printf(const char *fmt, ...);

int	main(void)
{
	char	*d = "hello world";
	char	c = 'a';
	int		i = 42069;
	int		j = 69420;

	ft_printf("character: %c\n", c);
	ft_printf("string: %s\n", d);
	ft_printf("integer: %i\n", i);
	ft_printf("decimal: %d\n", j);
	return (0);
}
