#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *format, ...);

int	main(void)
{
	ft_printf("pointer test: %p\n", 0);
	return (0);
}
