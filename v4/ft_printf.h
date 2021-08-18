/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:54:48 by hlehmann          #+#    #+#             */
/*   Updated: 2021/02/13 16:57:26 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	format_hexa_u(va_list *arguments);
int	format_hexa_l(va_list *arguments);
int	format_ptr(va_list *arguments);
int	format_char(va_list *arguments);
int	format_str(va_list *arguments);
int	format_int(va_list *arguments);
int	format_unsigned(va_list *arguments);

#endif
