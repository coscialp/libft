/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:01:22 by akerdeka          #+#    #+#             */
/*   Updated: 2021/04/09 12:06:07 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uintmax_t	ft_sqrt(uintmax_t x)
{
	uintmax_t		ret;
	uintmax_t		square;
	uintmax_t		threshold;

	ret = 0;
	threshold = (1ul << (4 * sizeof(uintmax_t) - 1));
	while (threshold)
	{
		square = (ret + threshold) * (ret + threshold);
		if (square <= x)
			ret += threshold;
		threshold >>= 1;
	}
	return (ret);
}
