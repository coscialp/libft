/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:30:09 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 15:35:50 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_pop(t_stack *stack)
{
	t_node_stack	*tmp;

	if (!stack)
		return ;
	if (stack->_data)
	{
		tmp = stack->_data->_next;
		ft_memdel((void **)&stack->_data);
		stack->_data = tmp;
		if (stack->_data)
			stack->_data->_prev = NULL;
		stack->_size--;
	}
}
