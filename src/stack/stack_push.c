/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:24:31 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/31 10:27:49 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_push(t_stack *stack, int data)
{
	t_node_stack	*new_node;
	t_node_stack	*tmp;

	tmp = stack->_data;
	if (tmp && tmp->value == data)
		return (-1);
	while (tmp && tmp->_next)
	{
		if (tmp->_next->value == data)
			return (-1);
		tmp = tmp->_next;
	}
	new_node = ft_calloc(sizeof(t_node_stack), 1);
	new_node->value = data;
	if (!stack->_data)
		stack->_data = new_node;
	else
	{
		new_node->_next = stack->_data;
		stack->_data->_prev = new_node;
		stack->_data = new_node;
	}
	stack->_size++;
	return (0);
}
