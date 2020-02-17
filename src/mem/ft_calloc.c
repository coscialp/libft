/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:22:22 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/17 12:59:48 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t nb, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size * nb)))
		return (NULL);
	ft_bzero(ptr, nb * size);
	return (ptr);
}
