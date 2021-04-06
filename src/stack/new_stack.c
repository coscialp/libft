/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:14:43 by coscialp          #+#    #+#             */
/*   Updated: 2021/04/06 13:49:35 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*new_stack(void)
{
	t_stack	*new;

	new = ft_xmalloc(sizeof(t_stack));
	new->_data = NULL;
	new->_size = 0;
	new->size = stack_size;
	new->pop = stack_pop;
	new->push = stack_push;
	new->last = stack_last;
	new->copy = stack_copy;
	return (new);
}

t_node_stack	*stack_last(t_stack *a)
{
	t_node_stack	*tmp;

	if (!a)
		return (NULL);
	tmp = a->_data;
	while (tmp && tmp->_next)
		tmp = tmp->_next;
	return (tmp);
}
