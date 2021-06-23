/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbernham <tbernham@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:44:44 by tbernham          #+#    #+#             */
/*   Updated: 2021/05/21 09:09:52 by tbernham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* format s_info cspdiuxX%												  */
/* c = char		s = string		p = pointer address in HEX					  */
/* d = decimal with sign		i = integer with sign						  */
/* u = unsigned integer			x = HEX integer wo sign lowercase             */
/* X = HEX integer wo sign uppercase	% = print % sign                      */
/*																			  */
/* flags: 	- = left-justified  0 = fill empty fields with 0                  */
/*  		. = precision		.* = int argument as precision .5	-> xxx10  */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_format	*s_info;
	int			len;

	s_info = (t_format *)malloc(sizeof(t_format));
	if (!s_info)
		return (-1);
	ft_initialize_struct(s_info);
	va_start(args, format);
	while (format[s_info->string_i])
	{
		if (format[s_info->string_i] == '%')
		{
			ft_check_specifier(format, s_info, args);
		}
		else
			s_info->len += write(1, &format[s_info->string_i++], 1);
	}
	va_end(args);
	len = s_info->len;
	free(s_info);
	return (len);
}
