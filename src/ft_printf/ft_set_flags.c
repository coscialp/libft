/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:47:38 by tclaudel          #+#    #+#             */
/*   Updated: 2021/03/04 13:03:23 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_printf	*ft_set_flags(t_printf *pf, char *str)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '%' && !ft_is_option(str[i]))
	{
		if (str[i] == '0')
		{
			if (!ft_isdigit(str[i - 1]) && str[i - 1] != '.')
			{
				pf->flags[j] = str[i];
				j++;
			}
		}
		else if (ft_is_flag(str[i]) && !ft_strchr(pf->flags, str[i]))
		{
			pf->flags[j] = str[i];
			j++;
		}
		i++;
	}
	return (pf);
}

char	*ft_new_fmt(char *old, t_printf *pf)
{
	size_t		i;
	char		*tmp;
	size_t		j;

	j = 0;
	i = 0;
	ft_bzero(pf->flags, 5);
	pf = ft_set_flags(pf, old);
	while (ft_strchr(pf->flags, old[j]))
		j++;
	tmp = ft_xmalloc(sizeof(char) * (ft_strlen(old) - j + 1 + 2));
	j = 0;
	while (old[i] && !ft_is_option(old[i]))
	{
		if (old[i] == '-')
			i++;
		else
			tmp[j++] = old[i++];
	}
	tmp[j] = 0;
	tmp = ft_strfjoin(tmp, old + i, 1);
	ft_memcpy(old, tmp, ft_strlen(tmp) + 1);
	ft_strdel(&tmp);
	return (old);
}
