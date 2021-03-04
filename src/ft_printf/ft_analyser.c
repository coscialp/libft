/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:17:15 by tclaudel          #+#    #+#             */
/*   Updated: 2021/03/04 12:52:03 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_analyser(char *tmp, t_printf *pf, va_list ap)
{
	tmp++;
	pf->option = 0;
	tmp = ft_new_fmt(tmp, pf);
	tmp = ft_set_width(tmp, pf, ap, 0);
	pf->option = tmp[0];
	tmp = ft_router(tmp + 1, pf, ap);
	return (tmp);
}

char	*ft_router(char *str, t_printf *pf, va_list ap)
{
	char	*tmp;

	tmp = ft_apply_convert(pf, ap);
	tmp = ft_apply_flags(tmp, pf);
	str = ft_strfjoin(tmp, str, 1);
	ft_bzero(&pf->width, sizeof(size_t) * 2);
	return (str);
}
