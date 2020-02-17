/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:11:41 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/17 12:58:53 by coscialp         ###   ########lyon.fr   */
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

char		*ft_ftoa(double fl, int second_part)
{
	int		entire;
	int		mult;
	int		after_point;
	int		decimal;
	char	*nbr;

	entire = (int)fl;
	fl = fl > 0 ? fl : -fl;
	if (!(nbr = ft_itoa(entire)))
		return (NULL);
	if (!(nbr = ft_strfjoin(nbr, ".", 1)))
		return (NULL);
	after_point = fl * size_fl(10, second_part);
	mult = size_fl(10, second_part - 1);
	while (second_part--)
	{
		decimal = mult == 0 ? 0 : after_point / mult;
		decimal %= 10;
		if (!(nbr = ft_strfjoin(nbr, ft_itoa(decimal), 3)))
			return (NULL);
		mult /= 10;
	}
	return (nbr);
}
