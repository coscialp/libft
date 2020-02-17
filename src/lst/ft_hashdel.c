/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:37:39 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/17 12:58:12 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hashdel(t_hash **hash, t_hash *next)
{
	t_hash *cpy;

	if (hash)
	{
		cpy = *hash;
		ft_memdel((void *)&cpy->key);
		ft_memdel((void *)&cpy->value);
		free(*hash);
		*hash = next;
	}
}
