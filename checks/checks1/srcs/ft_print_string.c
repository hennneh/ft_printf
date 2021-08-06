/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbernham <tbernham@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:44:44 by tbernham          #+#    #+#             */
/*   Updated: 2021/05/21 09:09:52 by tbernham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_read_string(t_format *s_info, va_list args)
{
	char	*ret;
	char	*tmp;

	tmp = va_arg(args, char *);
	if (tmp == NULL )
	{
		ret = ft_strdup("(null)");
		if (s_info->precision >= 6)
			s_info->precision = 6;
		else if (s_info->precision > 0)
			s_info->precision = -1;
	}	
	else
		ret = ft_strdup(tmp);
	s_info->nu_len = (int)ft_strlen(ret);
	return (ret);
}

char	*ft_string_precision(t_format *s_info, char *s1)
{
	char	*ret;
	int		len;

	if ((s_info->precision < 0) || (s_info->zero_prec
			&& s_info->precision == 0))
		return (ft_strdup(""));
	len = s_info->nu_len;
	if (s_info->precision >= len || s_info->precision == 0)
	{
		ret = (char *)ft_calloc(len + 1, sizeof(char));
		ft_memset(ret, ' ', len);
		ft_memcpy(&ret[len - s_info->nu_len], s1, s_info->nu_len);
	}	
	else
	{
		ret = (char *)ft_calloc(s_info->precision + 1, sizeof(char));
		ft_memcpy(ret, s1, s_info->precision);
	}	
	return (ret);
}

void	ft_print_string(t_format *s_info, va_list args)
{		
	char	*ret;
	char	*tmp;
	int		i;

	i = 0;
	ret = ft_read_string(s_info, args);
	tmp = ft_string_precision(s_info, ret);
	free(ret);
	ret = ft_number_width(s_info, tmp);
	while (ret[i])
		s_info->len += write(1, &ret[i++], 1);
	free(ret);
	free(tmp);
}
