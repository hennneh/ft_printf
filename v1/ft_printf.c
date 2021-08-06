/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:54:48 by hlehmann          #+#    #+#             */
/*   Updated: 2021/05/13 16:57:26 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags_func(const char *fmt, int *i, va_list args)
{
	struct	s_flags	flags;
	int		printed;
	(*i)++;
	if (s[i] == c)
		printed = ft_print_char(va_arg(args, int), flags);
	return (1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		printed;

	va_start(args, fmt);
	i = 0;
	printed = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
			printed += flags_func(fmt, &i, args);
		else
		{
			write(1, &fmt[i], 1);
			i++;
			printed++;
		}
	}
	va_end(args);
	return(printed);
}
