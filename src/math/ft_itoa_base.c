/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:42:14 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 11:38:42 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int ibase)
{
	static char	*base = "0123456789abcdef";
	static char	buf[12] = {'-'};
	int			i;
	int			neg;

	i = 10;
	buf[i + 1] = 0;
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
		buf[i--] = base[n % ibase];
		n /= ibase;
		if (n == 0)
			break ;
	}
	if (neg == -1)
		return (ft_strdup(buf + i));
	return (ft_strdup(buf + 1 + i));
}
