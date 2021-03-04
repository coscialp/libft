/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:54:44 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 11:59:24 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	static char	buf[12] = {0};
	int			i;
	int			neg;

	i = 10;
	neg = 1;
	if (n == INT_MIN)
		return (ft_strdup(STR_INT_MIN));
	if (n < 0)
	{
		neg = -1;
		n = -n;
	}
	while (1)
	{
		buf[i--] = n % 10 + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	if (neg == -1)
		buf[i] = '-';
	if (neg == -1)
		return (ft_strdup(buf + i));
	return (ft_strdup(buf + 1 + i));
}
