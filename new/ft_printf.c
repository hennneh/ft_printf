#include "ft_printf.h"

void    ft_print_x(unsigned int nbr)
{
        int		i;
        char	*s;

        s = "0123456789abcdef";
        i = nbr % 16;
        if (nbr / 16 > 0)
                ft_print_x(nbr / 16);
        write(1, &s[i], 1);
}

void	ft_print_u(unsigned int i)
{
	char	c;
	if (i / 10 > 0 )
		ft_print_u(i / 10);
	c = i % 10 + '0';
	write(1, &c, 1);
}

void	ft_print_id(int i)
{
	char	c;

	if (i < 0)
		write(1, "-", 1);
	if (i == -2147483648)
	{
		write(1, "2", 1);
		i = -147483648;
	}
	if (i < 0 )
		i *= -1;
	if (i / 10 > 0)
		ft_print_id(i / 10);
	c = i % 10 + '0';
	write(1, &c, 1);
}

void	ft_print_s(char *s)
{
	int	i;
	char	*tmp;

	tmp = s;
	i = 0;
	while (*tmp)
	{
		write(1, tmp, 1);
		tmp++;
	}
}

void	ft_print_c(char f)
{
	write(1, &f, 1);
}

int	check_flags(va_list args, const char *fmt, int *i)
{
	(*i)++;
	if (fmt[*i] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else if (fmt[*i] == 'c')
	{
		ft_print_c(va_arg(args, int));
		(*i)++;
	}
	else if (fmt[*i] == 's')
	{
		ft_print_s(va_arg(args, char *));
		(*i)++;
	}
	else if (fmt[*i] == 'd' || fmt[*i] == 'i')
	{
		ft_print_id(va_arg(args, int));
		(*i)++;
	}
	else if (fmt[*i] == 'u')
	{
		ft_print_u(va_arg(args, unsigned int));
		(*i)++;
	}
	else if (fmt[*i] == 'x')
	{
		ft_print_x(va_arg(args, unsigned int));
		(*i)++;
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		ret;
	int		i;

	va_start(args, fmt);
	ret = 0;
	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
			ret += check_flags(args, fmt, &i);
		else
		{
			write(1, &fmt[i], 1);
			i++;
			ret++;
		}
	}
	va_end(args);
	return (ret);
}
