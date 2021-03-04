/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:29:41 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 10:31:44 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_xmalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(1);
	return (ptr);
}
