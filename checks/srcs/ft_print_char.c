/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbernham <tbernham@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:44:44 by tbernham          #+#    #+#             */
/*   Updated: 2021/05/21 09:09:52 by tbernham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_c(t_format *s_info, char *ret)
{
	int	i;

	i = 0;
	while (s_info->width)
	{
		s_info->len += write(1, &ret[i++], 1);
		s_info->width--;
	}
}

void	ft_print_char(t_format *s_info, va_list args)
{
	char	*ret;
	int		i;

	i = 0;
	if (s_info->width == 0)
		s_info->width++;
	ret = (char *)ft_calloc(s_info->width + 1, sizeof(char));
	if (!ret)
		return ;
	if (s_info->l_justify || s_info->width_neg)
	{
		ret[i] = va_arg(args, int);
		ft_memset(&ret[i + 1], ' ', s_info->width - 1);
	}
	else
	{
		ft_memset(&ret[i], ' ', s_info->width - 1);
		ret[s_info->width - 1] = va_arg(args, int);
	}
	ft_print_c(s_info, ret);
	free(ret);
}
