/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbernham <tbernham>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:44:44 by tbernham          #+#    #+#             */
/*   Updated: 2021/05/11 14:44:44 by tbernham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dst_temp;
	char	*src_temp;
	size_t	i;

	i = 0;
	dst_temp = (char *)dst;
	src_temp = (char *)src;
	if (!dst)
		return (NULL);
	if (src_temp < dst_temp)
	{
		while (n > 0)
		{
			n--;
			dst_temp[n] = src_temp[n];
		}
		return (dst);
	}
	while (i < n)
	{
		dst_temp[i] = src_temp[i];
		i++;
	}
	return (dst);
}
