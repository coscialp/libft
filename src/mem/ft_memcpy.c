/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:49:44 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 10:28:14 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*s;
	char			*d;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	s = (const char *)src;
	d = (char *)dest;
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
