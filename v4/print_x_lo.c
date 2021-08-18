/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:54:48 by hlehmann          #+#    #+#             */
/*   Updated: 2021/02/13 16:57:26 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	treat_zero(long int number)
{
	if (number == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	return (0);
}

int	print_x_lo(va_list *arguments)
{
	char		hexa_num[100];
	int			i;
	int			j;
	int			temp;
	long int	number;

	i = 1;
	number = va_arg(*arguments, unsigned int);
	if (treat_zero(number))
		return (1);
	while (number != 0)
	{
		temp = number % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hexa_num[i++] = temp;
		number = number / 16;
	}
	j = i;
	while (--j > 0)
		ft_putchar_fd(hexa_num[j], 1);
	return (i - 1);
}
