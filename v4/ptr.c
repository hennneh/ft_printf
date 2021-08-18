/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:54:48 by hlehmann          #+#    #+#             */
/*   Updated: 2021/02/13 16:57:26 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	treat_zero(unsigned long number)
{
	if (number == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (1);
	}
	return (0);
}

int	print_p(va_list *arguments)
{
	unsigned long	number;
	char			hex[11];
	int				i;
	int				j;
	int				temp;

	i = 1;
	number = va_arg(*arguments, unsigned long);
	if (treat_zero(number))
		return (3);
	while (number != 0)
	{
		temp = number % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hex[i++] = temp;
		number = number / 16;
	}
	j = i;
	ft_putstr_fd("0x", 1);
	while (--j > 0)
		ft_putchar_fd(hex[j], 1);
	return (i + 1);
}
