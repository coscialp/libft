/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:31:14 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 10:56:03 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sep(char c, const char *sep)
{
	size_t		i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t		i;
	size_t		j;
	size_t		size;
	char		*str;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_is_sep(s1[i], set) && s1[i])
		i++;
	if (i - 1 == j)
	{
		str = (char *)ft_xmalloc(sizeof(char) * 1);
		return (str);
	}
	while (ft_is_sep(s1[j], set))
		j--;
	size = (j - i + 1);
	str = ft_strndup((s1 + i), size);
	return (str);
}
