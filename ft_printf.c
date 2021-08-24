/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:54:48 by hlehmann          #+#    #+#             */
/*   Updated: 2021/02/13 16:57:26 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cases(const char *format, int current_char, va_list *arguments)
{
	char	next_char;
	int		length;

	length = 1;
	next_char = format[current_char + 1];
	if (next_char == 0 || next_char == '\0')
		return (0);
	if (next_char == 'c')
		length = print_c(arguments);
	else if (next_char == 's')
		length = print_s(arguments);
	else if (next_char == 'p')
		length = print_p(arguments);
	else if (next_char == 'd' || next_char == 'i')
		length = print_i(arguments);
	else if (next_char == 'u')
		length = print_u(arguments);
	else if (next_char == 'X')
		length = print_x_up(arguments);
	else if (next_char == 'x')
		length = print_x_lo(arguments);
	else if (next_char == '%')
		ft_putchar_fd('%', 1);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int		length;
	int		char_counter;
	int		printed;
	va_list	arguments;

	length = 0;
	char_counter = 0;
	va_start(arguments, format);
	while (format[char_counter])
	{
		if (format[char_counter] != '%')
		{
			length++;
			ft_putchar_fd(format[char_counter], 1);
		}
		else
		{
			printed = cases(format, char_counter, &arguments);
			char_counter++;
			length += printed;
		}
		char_counter++;
	}
	va_end(arguments);
	return (length);
}
