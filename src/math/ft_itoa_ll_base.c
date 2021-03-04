/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:31:25 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 11:13:32 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_ll_base(unsigned long n, char *base)
{
	static char	buf[18] = {0};
	int			i;
	int			lbase;

	lbase = ft_strlen(base);
	i = 16;
	while (1)
	{
		buf[i--] = base[n % lbase];
		n /= lbase;
		if (n == 0)
			break ;
	}
	return (ft_strdup(buf + 1 + i));
}
