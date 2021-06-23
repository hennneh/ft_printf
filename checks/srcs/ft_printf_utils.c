/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbernham <tbernham@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:44:44 by tbernham          #+#    #+#             */
/*   Updated: 2021/05/21 09:09:52 by tbernham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_format	*ft_initialize_struct(t_format *format)
{
	format->width = 0;
	format->precision = 0;
	format->zero_prec = 0;
	format->zero_pad = 0;
	format->l_justify = 0;
	format->len = 0;
	format->sign = 0;
	format->is_zero = 0;
	format->perc = 0;
	format->string_i = 0;
	format->var_type = 0;
	format->nu_neg = 0;
	format->nu_len = 0;
	format->nu_zero = 0;
	format->width_neg = 0;
	return (format);
}

t_format	*ft_reset_struct(t_format *format)
{
	format->width = 0;
	format->precision = 0;
	format->zero_prec = 0;
	format->zero_pad = 0;
	format->l_justify = 0;
	format->sign = 0;
	format->is_zero = 0;
	format->perc = 0;
	format->var_type = 0;
	format->nu_neg = 0;
	format->nu_len = 0;
	format->nu_zero = 0;
	format->width_neg = 0;
	return (format);
}

int	ft_is_not_last_specifier(const char *fmt, const t_format *s_info)
{	
	if ((fmt[s_info->string_i] == 'c') || (fmt[s_info->string_i] == 's')
		|| (fmt[s_info->string_i] == 'd') || (fmt[s_info->string_i] == 'i')
		|| (fmt[s_info->string_i] == 'u') || (fmt[s_info->string_i] == '%')
		|| (fmt[s_info->string_i] == 'x') || (fmt[s_info->string_i] == 'X')
		|| (fmt[s_info->string_i] == 'p'))
		return (1);
	else
		return (0);
}

void	ft_convert_variable(t_format *s_info, va_list args)
{
	if (s_info->var_type == 'c')
		ft_print_char(s_info, args);
	if (s_info->var_type == 's')
		ft_print_string(s_info, args);
	if (s_info->var_type == 'd')
		ft_print_decimal(s_info, args);
	if (s_info->var_type == 'i')
		ft_print_decimal(s_info, args);
	if (s_info->var_type == 'u')
		ft_print_decimal(s_info, args);
	if (s_info->var_type == 'p')
		ft_print_pointer(s_info, args);
	if (s_info->var_type == '%')
		s_info->len += write(1, "%", 1);
	if ((s_info->var_type == 'x') || (s_info->var_type == 'X'))
		ft_print_hex(s_info, args);
	ft_reset_struct(s_info);
}

/* ************************************************************************** */
/* format contains position of current char, not the beginning                */
/* ************************************************************************** */

void	ft_check_specifier(const char *fmt, t_format *s_info, va_list args)
{
	s_info->string_i++;
	if (fmt[s_info->string_i] == '%')
	{
		s_info->len += write(1, "%", 1);
		s_info->string_i++;
	}
	else
	{
		while (!ft_is_not_last_specifier(fmt, s_info))
		{
			if (fmt[s_info->string_i] == '-')
				ft_get_l_justify(s_info);
			if (fmt[s_info->string_i] == '0')
				ft_get_padding(s_info, fmt);
			if (fmt[s_info->string_i] == '*')
				ft_get_width_by_star(s_info, args);
			if (fmt[s_info->string_i] == '.')
				ft_get_precision(fmt, s_info, args);
			if (ft_isdigit(fmt[s_info->string_i]))
				ft_get_width_by_value(fmt, s_info);
		}
		s_info->var_type = (char)fmt[s_info->string_i];
		s_info->string_i++;
		ft_convert_variable(s_info, args);
	}
}
