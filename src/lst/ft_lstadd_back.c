/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:27:58 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/17 12:58:20 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;

	if (!alst)
		return ;
	if (!(*alst))
		*alst = new;
	else if (new != NULL)
	{
		list = *alst;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
}
