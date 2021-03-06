/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:10:27 by tclaudel          #+#    #+#             */
/*   Updated: 2021/03/09 09:31:30 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (ft_strchr(s2, s1[i]))
		i++;
	return (i);
}

size_t	ft_strcspn(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (!ft_strchr(s2, s1[i]))
		i++;
	return (i);
}

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*begin;
	char	*end;

	begin = *stringp;
	if (begin == NULL)
		return (NULL);
	end = begin + ft_strcspn(begin, delim);
	if (*end)
	{
		*end++ = '\0';
		*stringp = end;
	}
	else
		*stringp = NULL;
	return (begin);
}

char	*ft_strtok(char *s, const char *charset)
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
