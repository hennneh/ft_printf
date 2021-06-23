/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbernham <tbernham>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:44:44 by tbernham          #+#    #+#             */
/*   Updated: 2021/05/11 14:44:44 by tbernham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_str(char c, char const *set)
	{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*rtn;
	int			i;
	int			start;
	int			end;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	end = (ft_strlen(s1));
	while (ft_is_in_str(s1[start], set))
		start++;
	while (ft_is_in_str(s1[end - 1], set))
		end--;
	if (end - start <= 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	rtn = (char *)ft_calloc((end - start) + 1, sizeof(char));
	if (!rtn)
		return (NULL);
	while (((start + i) <= end - 1) && end > 0)
	{
		rtn[i] = s1[start + i];
		i++;
	}
	return (rtn);
}
