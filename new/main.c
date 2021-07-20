#include <stdio.h>

int     ft_printf(const char *fmt, ...);

int	main(void)
{
	char	*d = "hello world";
	char	c = 'a';
	int		i = 42069;
	int		j = 69420;
	unsigned int	k = 4294967295;

	ft_printf("character: %c\n", c);
	ft_printf("string: %s\n", d);
	ft_printf("integer: %i\n", i);
	ft_printf("decimal: %d\n", j);
	ft_printf("unsigned: %u\n", k);
	ft_printf("all: %c\n%s\n%i\n%d\n%u\n", c, d, i, j, k);
	return (0);
}
