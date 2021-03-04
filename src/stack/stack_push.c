/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:24:31 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 15:29:43 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_push(t_stack *stack, int data)
{
	t_node_stack	*new_node;

	if (!stack)
		return ;
	new_node = ft_xmalloc(sizeof(t_node_stack));
	new_node->value = data;
	new_node->_next = NULL;
	new_node->_prev = NULL;
	if (!stack->_data)
		stack->_data = new_node;
	else
	{
		new_node->_next = stack->_data;
		stack->_data->_prev = new_node;
		stack->_data = new_node;
	}
	stack->_size++;
}
