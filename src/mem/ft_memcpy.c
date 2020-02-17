/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:49:44 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/17 13:00:01 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
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
