/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwcdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:08:35 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 10:53:05 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strwcdup(char *src, char c)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == c)
			j++;
		i++;
	}
	dest = (char *)ft_xmalloc(sizeof(char) * (i - j) + 1);
	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == c)
			i++;
		dest[j++] = src[i++];
	}
	dest[j] = 0;
	return (dest);
}
