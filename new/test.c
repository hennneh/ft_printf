#include <stdio.h>
#include <unistd.h>

void	ft_print_x(unsigned int nbr)
{
	int		i;
	char	*s;

	s = "0123456789abcdef";
	i = nbr % 16;
	if (nbr / 16 > 0)
		ft_print_x(nbr / 16);
	write(1, &s[i], 1);
}

int	main(void)
{
	unsigned int	i = 7562;

	printf("value to be printed: %i\nhex-value: %x\n", i, i);
	write(1, "my code: ", 9);
	ft_print_x(i);
	printf("\n");
	return (0);
}
