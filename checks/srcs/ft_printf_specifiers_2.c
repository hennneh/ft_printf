/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifiers_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbernham <tbernham@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:44:44 by tbernham          #+#    #+#             */
/*   Updated: 2021/05/21 09:09:52 by tbernham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_get_precision_value(const char *fmt, t_format *s_info, va_list args)
{
	int	i;
	int	temp;

	temp = 0;
	i = 1;
	if (fmt[s_info->string_i] == '*')
	{
		s_info->precision = va_arg(args, int);
		if (s_info->precision < 0)
			s_info->precision = 0;
		else if (s_info->precision == 0)
			s_info->zero_prec = 1;
		s_info->string_i++;
	}		
	else
	{
		temp = ft_atoi(&fmt[s_info->string_i]);
		s_info->precision = temp;
		while (temp / 10)
		{
			temp /= 10;
			i++;
		}	
		s_info->string_i += i;
	}
}

void	ft_get_precision(const char *fmt, t_format *s_info, va_list args)
{
	if (((!ft_isdigit((int)(fmt[s_info->string_i + 1])))
		|| (fmt[s_info->string_i + 1] == '0'))
		&& (fmt[s_info->string_i + 1] != '*'))
	{
		while (fmt[s_info->string_i + 1] == '0')
			s_info->string_i++;
		if ((!(ft_isdigit((int)(fmt[s_info->string_i + 1])))))
		{
			if (fmt[s_info->string_i] != '0'
				&& (ft_isdigit((int)(fmt[s_info->string_i - 1]))))
				s_info->precision = -1;
			if (fmt[s_info->string_i] == '0' || fmt[s_info->string_i] == '.')
				s_info->zero_prec = 1;
			s_info->string_i++;
			return ;
		}
	}
	s_info->string_i++;
	ft_get_precision_value(fmt, s_info, args);
}
