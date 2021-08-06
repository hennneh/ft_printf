/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbernham <tbernham@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:44:44 by tbernham          #+#    #+#             */
/*   Updated: 2021/05/21 09:09:52 by tbernham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_nbr_to_base(unsigned long n, char *base, char *ret)
{
	unsigned long	base_len;
	unsigned long	num;

	num = n;
	base_len = ft_strlen(base);
	if (num == 0)
	{
		ret[ft_strlen(ret)] = '0';
		return (ret);
	}
	if (num >= base_len)
	{
		ft_nbr_to_base(num / base_len, base, ret);
		ret[ft_strlen(ret)] = (base[num % base_len]);
	}
	else if (num < base_len)
		ret[ft_strlen(ret)] = (base[num]);
	return (ret);
}

void	ft_print_pointer(t_format *s_info, va_list args)
{
	unsigned long	ptr;
	char			*ret;
	char			*tmp;
	int				i;

	i = 0;
	ptr = (unsigned long)va_arg(args, void *);
	ret = (char *)ft_calloc(20, sizeof(char));
	ft_nbr_to_base(ptr, "0123456789abcdef", ret);
	tmp = ft_strjoin("0x", ret);
	if (!tmp)
		return ;
	free(ret);
	ret = ft_number_width(s_info, tmp);
	while (ret[i])
		s_info->len += write(1, &ret[i++], 1);
	free(tmp);
	free(ret);
}
