/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:59:07 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 11:13:15 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_return_nbr(long nb, int ibase, char *base)
{
	if (nb >= ibase)
	{
		ft_return_nbr((nb / ibase), ibase, base);
		ft_return_nbr((nb % ibase), ibase, base);
	}
	else
		ft_putchar(base[nb]);
}

int	ft_is_base(char *base)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	j = 0;
	while (base[j] != '\0')
	{
		k = j + 1;
		while (base[k] != '\0')
		{
			if (base[j] == base[k])
				return (0);
			k++;
		}
		j++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		ibase;
	long	nb;

	i = 0;
	nb = nbr;
	ibase = ft_is_base(base);
	if (ibase == 0 || ibase == 1)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	ft_return_nbr(nb, ibase, base);
}
