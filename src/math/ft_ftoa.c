/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:11:41 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 12:01:53 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_fl(int x, unsigned int y)
{
	if (y == 0)
		return (1);
	else if (y % 2 == 0)
		return (size_fl(x, y / 2) * size_fl(x, y / 2));
	else
		return (x * size_fl(x, y / 2) * size_fl(x, y / 2));
}

char	*ft_ftoa(double fl, int second_part)
{
	int		entire;
	int		mult;
	int		after_point;
	int		decimal;
	char	*nbr;

	entire = (int)fl;
	if (fl < 0)
		fl = -fl;
	nbr = ft_itoa(entire);
	nbr = ft_strfjoin(nbr, ".", 1);
	after_point = fl * size_fl(10, second_part);
	mult = size_fl(10, second_part - 1);
	while (second_part--)
	{
		decimal = after_point / mult;
		if (mult == 0)
			decimal = 0;
		decimal %= 10;
		nbr = ft_strfjoin(nbr, ft_itoa(decimal), 3);
		mult /= 10;
	}
	return (nbr);
}
