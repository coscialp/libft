/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:24:20 by tclaudel          #+#    #+#             */
/*   Updated: 2021/03/04 13:03:42 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin_zero(char *s1, char *s2)
{
	size_t		lmalloc;
	char		*str;
	size_t		i;
	size_t		ls1;

	i = 0;
	ls1 = ft_strlen(s1);
	lmalloc = ls1 + ft_strlen(s2);
	str = (char *)ft_calloc(sizeof(char), (lmalloc + 2));
	ft_memcpy(str, s1, ls1);
	ft_memcpy(str + ls1 + 1, s2, ft_strlen(s2) + 1);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (str);
}
