/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:08:28 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 11:00:06 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t		size;
	size_t		i;
	char		*dest;

	i = 0;
	size = ft_strlen(str);
	dest = (char *)ft_calloc(sizeof(char), size + 1);
	ft_memcpy(dest, str, size);
	return (dest);
}
