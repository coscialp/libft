/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:58:17 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 11:11:25 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *s1, void *s2, size_t size1, size_t size2)
{
	void	*ptr;

	ptr = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		ptr = ft_memalloc(size2 + 1);
		return (ft_memcpy(ptr, s2, size2));
	}
	if (!s2)
	{
		ptr = ft_memalloc(size1 + 1);
		return (ft_memcpy(ptr, s1, size1));
	}
	ptr = ft_memalloc(size1 + size2 + 1);
	ft_memcpy(ptr, s1, size1);
	ft_memcpy(ptr + size1, s2, size2 + 1);
	return (ptr);
}
