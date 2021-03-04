/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:01:38 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 10:55:51 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		l;
	size_t		lmalloc;
	char		*str;

	i = 0;
	l = ft_strlen(s);
	if ((start >= l) || (len == 0))
		return (ft_calloc(sizeof(char), 1));
	if (start - l < len)
		lmalloc = start - l;
	else
		lmalloc = len;
	str = (char *)ft_calloc(sizeof(char), lmalloc + 1);
	while (len--)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	return (str);
}
