/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:22:22 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 10:31:53 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void	*ptr;

	ptr = ft_xmalloc(size * nb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nb * size);
	return (ptr);
}
