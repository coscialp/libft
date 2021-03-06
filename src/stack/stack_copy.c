/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:21:26 by akerdeka          #+#    #+#             */
/*   Updated: 2021/04/09 14:17:13 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_copy(t_stack *stack)
{
	t_stack			*copy;
	t_node_stack	*cur;

	copy = new_stack();
	if (stack)
	{
		cur = stack->last(stack);
		while (cur)
		{
			copy->push(copy, cur->value);
			cur = cur->_prev;
		}
	}
	return (copy);
}
