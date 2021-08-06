/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbernham <tbernham@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:44:44 by tbernham          #+#    #+#             */
/*   Updated: 2021/05/21 09:09:52 by tbernham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_read_number(t_format *s_info, va_list args)
{
	char	*ret;
	char	*trim;
	long	tmp;

	if (s_info->var_type == 'u')
	{
		tmp = (long)va_arg(args, unsigned int);
		if (tmp == 0)
			s_info->nu_zero = 1;
		ret = ft_uitoa((unsigned int)tmp);
	}		
	else
	{
		tmp = (long)va_arg(args, int);
		if (tmp < 0)
			s_info->nu_neg = 1;
		if (tmp == 0)
			s_info->nu_zero = 1;
		ret = ft_itoa((int)tmp);
	}
	trim = ft_strtrim(ret, "-");
	free(ret);
	s_info->nu_len = (int)ft_strlen(trim);
	return (trim);
}

char	*ft_number_precision(t_format *s_info, char *number)
{
	char	*ret;
	int		len;

	if ((s_info->zero_prec && s_info->nu_zero)
		|| (s_info->zero_pad && s_info->precision < 0 && s_info->nu_zero))
		return (ft_strdup(""));
	if (s_info->nu_len > s_info->precision)
		len = s_info->nu_len;
	else
		len = s_info->precision;
	if (s_info->nu_neg)
		len++;
	ret = (char *)ft_calloc(len + 1, sizeof(char));
	ft_memset(ret, '0', len);
	if (s_info->nu_neg)
		ft_memset(ret, '-', 1);
	ft_memcpy(&ret[len - s_info->nu_len], number, s_info->nu_len);
	return (ret);
}

char	*ft_number_width(t_format *s_info, char *number)
{
	int		len;
	char	*tmp;

	len = ft_strlen(number);
	if (len > s_info->width)
	{
		tmp = (char *)ft_calloc((len + 1), sizeof(char));
		ft_memcpy(tmp, number, len);
	}	
	else
	{
		tmp = (char *)ft_calloc((s_info->width + 1), sizeof(char));
		if (!tmp)
			return (NULL);
		ft_memset(tmp, ' ', s_info->width);
		if (s_info->l_justify || s_info->width_neg)
			ft_memcpy(tmp, number, len);
		else
			ft_memcpy(&tmp[s_info->width - len], number, len);
	}
	return (tmp);
}

char	*ft_number_padding(t_format *s_info, char *number)
{
	char	*tmp;

	tmp = ft_strdup(number);
	if ((!(s_info->width >= (int)ft_strlen(tmp))) || s_info->precision > 0
		|| !s_info->zero_pad || (s_info->nu_zero && s_info->zero_prec))
		return (tmp);
	if (s_info->precision < 0)
	{
		free (tmp);
		return (ft_strdup(""));
	}
	if (s_info->zero_pad && !s_info->width_neg && !s_info->zero_prec)
	{
		if (s_info->nu_neg)
		{
			ft_memset(tmp, '-', 1);
			ft_memset(&tmp[1], '0', s_info->width - s_info->nu_len - 1);
		}
		else
			ft_memset(tmp, '0', s_info->width - s_info->nu_len);
	}
	return (tmp);
}

void	ft_print_decimal(t_format *s_info, va_list args)
{
	char	*number;
	char	*tmp;
	int		i;

	i = 0;
	number = ft_read_number(s_info, args);
	tmp = ft_number_precision(s_info, number);
	free(number);
	number = ft_number_width(s_info, tmp);
	free(tmp);
	tmp = ft_number_padding(s_info, number);
	while (tmp[i])
		s_info->len += write(1, &tmp[i++], 1);
	free(tmp);
	free(number);
}
