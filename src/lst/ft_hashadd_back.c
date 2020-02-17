/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:13:29 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/17 12:58:07 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hashadd_back(t_hash **hash, t_hash *new)
{
	t_hash	*list;

	if (!hash)
		return ;
	if (!(*hash))
		*hash = new;
	else if (new)
	{
		list = *hash;
		while (list->next)
			list = list->next;
		list->next = new;
		list = list->next;
		list->top = *hash;
	}
}
