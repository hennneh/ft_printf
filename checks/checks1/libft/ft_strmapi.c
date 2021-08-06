/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbernham <tbernham>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:44:44 by tbernham          #+#    #+#             */
/*   Updated: 2021/05/11 14:44:44 by tbernham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*rtn;

	if (!s || !(*f))
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	rtn = ft_calloc((i + 1), sizeof(char));
	if (!rtn)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rtn[i] = f(i, s[i]);
		i++;
	}
	return (rtn);
}
