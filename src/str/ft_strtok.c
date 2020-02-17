/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:10:27 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 17:26:43 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_strspn(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (ft_strchr(s2, s1[i]))
		i++;
	return (i);
}

static size_t		ft_strcspn(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (!ft_strchr(s2, s1[i]))
		i++;
	return (i);
}

char		*ft_strtok(char *s, const char *charset)
{
	char			*end;
	static char		*save_str;

	if (s == NULL)
		s = save_str;
	if (*s == '\0')
	{
		save_str = s;
		return (NULL);
	}
	s += ft_strspn(s, charset);
	if (*s == '\0')
	{
		save_str = s;
		return (NULL);
	}
	end = s + ft_strcspn(s, charset);
	if (*end == '\0')
	{
		save_str = end;
		return (s);
	}
	*end = '\0';
	save_str = end + 1;
	return (s);
}
