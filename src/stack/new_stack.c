/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:14:43 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/09 17:49:54 by coscialp         ###   ########lyon.fr   */
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
	return (new);
}

t_node_stack	*stack_last(t_stack *a)
{
	t_node_stack *tmp;

	tmp = a->_data;
	while (tmp->_next)
		tmp =tmp->_next;
	return (tmp);
}