/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbernham <tbernham@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:44:44 by tbernham          #+#    #+#             */
/*   Updated: 2021/05/21 09:09:52 by tbernham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_hex_uppercase(char *ret)
{
	int		i;
	int		c;

	i = 0;
	while (ret[i])
	{
		c = ft_toupper(ret[i]);
		ret[i] = c;
		i++;
	}
}

void	ft_print_hex(t_format *s_info, va_list args)
{
	long	number;
	char	*tmp;
	char	*ret;
	int		i;

	i = 0;
	number = (unsigned long)va_arg(args, unsigned int);
	if (number == 0)
		s_info->nu_zero = 1;
	ret = (char *)ft_calloc(20, sizeof(char));
	if (!ret)
		return ;
	ft_nbr_to_base(number, "0123456789abcdef", ret);
	s_info->nu_len = (int)ft_strlen(ret);
	if (s_info->var_type == 'X')
		ft_hex_uppercase(ret);
	tmp = ft_number_precision(s_info, ret);
	free(ret);
	ret = ft_number_width(s_info, tmp);
	free(tmp);
	tmp = ft_number_padding(s_info, ret);
	while (tmp[i])
		s_info->len += write(1, &tmp[i++], 1);
	free(tmp);
	free(ret);
}
