/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbernham <tbernham@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:44:44 by tbernham          #+#    #+#             */
/*   Updated: 2021/05/21 09:09:52 by tbernham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_get_padding(t_format *s_info, const char *fmt)
{
	s_info->zero_pad = 1;
	while (fmt[s_info->string_i] == '0')
		s_info->string_i++;
	if (fmt[s_info->string_i] == '-')
		s_info->zero_pad = 0;
}

void	ft_get_width_by_star(t_format *s_info, va_list args)
{
	s_info->string_i++;
	s_info->width = va_arg(args, int);
	if (s_info->width < 0)
	{
		s_info->width *= -1;
		s_info->width_neg = 1;
	}
}

void	ft_get_l_justify(t_format *s_info)
{
	s_info->string_i++;
	s_info->l_justify = 1;
}

void	ft_get_width_by_value(const char *fmt, t_format *s_info)
{
	int	i;
	int	temp;

	temp = 0;
	i = 1;
	temp = ft_atoi(&fmt[s_info->string_i]);
	s_info->width = temp;
	while (temp / 10)
	{
		temp /= 10;
		i++;
	}	
	s_info->string_i += i;
}
