/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbernham <tbernham@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:44:44 by tbernham          #+#    #+#             */
/*   Updated: 2021/05/21 09:09:52 by tbernham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# include "../libft/libft.h"

typedef struct s_format
{
	va_list	args;
	int		width;
	int		precision;
	int		zero_prec;
	int		zero_pad;
	int		l_justify;
	int		len;
	int		sign;
	int		is_zero;
	int		perc;
	int		string_i;
	char	var_type;
	int		nu_neg;
	int		nu_len;
	int		nu_zero;
	int		width_neg;
}	t_format;

t_format	*ft_initialize_struct(t_format *format);
t_format	*ft_reset_struct(t_format *format);
void		ft_check_specifier(const char *fmt, t_format *s_info, va_list args);
void		ft_get_padding(t_format *s_info, const char *fmt);
void		ft_get_width_by_star(t_format *s_info, va_list args);
void		ft_get_l_justify(t_format *s_info);
void		ft_get_precision(const char *fmt, t_format *s_info, va_list args);
void		ft_get_width_by_value(const char *fmt, t_format *s_info);
void		ft_print_char(t_format *s_info, va_list args);
void		ft_print_string(t_format *s_info, va_list args);
void		ft_print_decimal(t_format *s_info, va_list args);
void		ft_print_pointer(t_format *s_info, va_list args);
char		*ft_number_width(t_format *s_info, char *number);
void		ft_print_hex(t_format *s_info, va_list args);
char		*ft_nbr_to_base(unsigned long n, char *base, char *ret);
char		*ft_number_padding(t_format *s_info, char *number);
char		*ft_number_precision(t_format *s_info, char *number);

#endif