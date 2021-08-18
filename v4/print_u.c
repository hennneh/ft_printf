/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:54:48 by hlehmann          #+#    #+#             */
/*   Updated: 2021/02/13 16:57:26 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_len(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_put_unsigned(unsigned int n, int fd)
{
	char				s[11];
	unsigned int		counter;
	int					i;

	i = 1;
	counter = n / 10;
	while (counter)
	{
		counter /= 10;
		i++;
	}
	s[i] = '\0';
	while (i--)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
	}
	ft_putstr_fd(s, fd);
}

int	print_u(va_list *arguments)
{
	unsigned int	number;

	number = va_arg(*arguments, unsigned int);
	ft_put_unsigned(number, 1);
	number = ft_len((long)number);
	return (number);
}
