/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:08:28 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/17 13:01:28 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	size_t		size;
	size_t		i;
	char		*dest;

	i = 0;
	size = ft_strlen(str);
	if (!(dest = (char*)ft_calloc(sizeof(char), size + 1)))
		return (NULL);
	ft_memcpy(dest, str, size);
	return (dest);
}
