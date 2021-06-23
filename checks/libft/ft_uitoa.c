/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbernham <tbernham>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:44:44 by tbernham          #+#    #+#             */
/*   Updated: 2021/05/11 14:44:44 by tbernham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_nbr_size(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size = 2;
	else
	{
		while (n)
		{
			n /= 10;
			size++;
		}
		size = size + 1;
	}
	return (size);
}

char	*ft_uitoa(unsigned int n)
{
	int		size;
	char	*rtn;

	size = ft_get_nbr_size(n);
	rtn = (char *)(ft_calloc(size, sizeof(char)));
	if (rtn)
	{
		while (size - 1)
		{
			rtn[size - 2] = n % 10 + '0';
			n /= 10;
			size--;
		}
	}
	return (rtn);
}
