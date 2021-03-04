/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:48:12 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 11:11:40 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;
	char		*d;
	char		*s;

	i = 0;
	if (!(dest && src))
		return (0);
	d = (char *)dest;
	s = (char *)src;
	if (d < s)
	{
		while (n--)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		while (n--)
			d[n] = s[n];
	return (dest);
}
