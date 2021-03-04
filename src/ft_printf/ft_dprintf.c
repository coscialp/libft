/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:49:20 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 13:10:05 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_core_dprintf(const char *s, size_t pos, t_printf *pf, va_list ap)
{
	char		**tmp;
	char		*result;

	pos = (char *)ft_memchr(s, '%', ft_strlen(s)) - s;
	result = ft_strndup(s, pos);
	s += pos;
	while (*s)
	{
		tmp = ft_set_tmp(s);
		s += ft_strlen(tmp[0]) + ft_strlen(tmp[1]);
		tmp[2] = ft_strfjoin(tmp[0], tmp[1], 3);
		tmp[3] = ft_analyser(tmp[2], pf, ap);
		free(tmp[2]);
		result = ft_join_result(result, tmp[3], pf);
		free(tmp);
	}
	pos += pf->return_size;
	write(pf->fd, result, pos);
	free(result);
	return (pos);
}

int	ft_dprintf(int fd, const char *s, ...)
{
	va_list		ap;
	size_t		pos;
	t_printf	*pf;

	pos = 0;
	va_start(ap, s);
	pf = setup_struct();
	pf->fd = fd;
	if (!ft_memchr(s, '%', ft_strlen(s)))
	{
		ft_putstr_fd(s, fd);
		va_end(ap);
		free(pf);
		return (ft_strlen(s));
	}
	pos = ft_core_dprintf(s, pos, pf, ap);
	va_end(ap);
	free(pf);
	return (pos);
}
