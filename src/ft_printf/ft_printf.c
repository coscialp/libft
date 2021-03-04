/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:46:55 by tclaudel          #+#    #+#             */
/*   Updated: 2021/03/04 13:09:07 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_printf	*setup_struct(void)
{
	t_printf	*setup;

	setup = ft_xmalloc(sizeof(t_printf));
	setup->width = 0;
	setup->option = 0;
	setup->accu = 0;
	setup->zero = 0;
	setup->sign = 0;
	setup->fd = 0;
	setup->return_size = 0;
	ft_bzero(setup->flags, 5);
	return (setup);
}

char	*ft_join_result(char *result, char *tmp, t_printf *pf)
{
	pf->return_size += ft_strlen(tmp);
	if (pf->option == 'c' && pf->zero == 1)
		result = ft_strjoin_zero(result, tmp);
	else
		result = ft_strfjoin(result, tmp, 3);
	return (result);
}

char	**ft_set_tmp(const char *str)
{
	char	**tmp;
	size_t	i;
	size_t	j;

	tmp = ft_xmalloc(sizeof(char *) * 4);
	i = 1;
	while (ft_isdigit(str[i]) || ft_is_flag(str[i]))
		i++;
	i++;
	j = i;
	while (str[j] && str[j] != '%')
		j++;
	tmp[0] = ft_strndup(str, i);
	tmp[1] = ft_strndup(str + i, j - i);
	return (tmp);
}

int	ft_core_printf(const char *s, size_t pos, t_printf *pf, va_list ap)
{
	char	**tmp;
	char	*result;

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
	write(1, result, pos);
	free(result);
	return (pos);
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	size_t		pos;
	t_printf	*pf;

	pos = 0;
	va_start(ap, s);
	pf = setup_struct();
	if (!ft_memchr(s, '%', ft_strlen(s)))
	{
		ft_putstr(s);
		va_end(ap);
		free(pf);
		return (ft_strlen(s));
	}
	pos = ft_core_printf(s, pos, pf, ap);
	va_end(ap);
	free(pf);
	return (pos);
}
