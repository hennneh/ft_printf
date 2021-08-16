#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *format, ...);

int	main(void)
{
	int	i;
	int *pi;

	i = 0;
	pi = &i;
	ft_printf("pointer test: %p\n", pi);
	return (0);
}
