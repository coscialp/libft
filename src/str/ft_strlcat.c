/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:42:12 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 10:58:35 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			i;
	size_t			j;
	size_t			n;
	size_t			destsize;

	j = 0;
	destsize = ft_strnlen(dest, size);
	i = destsize;
	n = size - destsize;
	if (n == 0)
		return (destsize + ft_strlen(src));
	while (src[j] != '\0')
	{
		if (n != 1)
		{
			dest[i] = src[j];
			n--;
			i++;
		}
		j++;
	}
	dest[i] = '\0';
	return (destsize + ft_strlen(src));
}
