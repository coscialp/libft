/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:02:25 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/12 09:24:59 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct s_node_stack	t_node_stack;
struct s_node_stack
{
	int				value;
	size_t			sort_value;
	t_node_stack	*_next;
	t_node_stack	*_prev;
};

typedef struct s_stack		t_stack;
struct s_stack
{
	t_node_stack	*_data;
	size_t			_size;
	int				(*push)(t_stack *, int);
	void			(*pop)(t_stack *);
	size_t			(*size)(t_stack *);
	t_stack			*(*copy)(t_stack *);
	t_node_stack	*(*last)(t_stack *);
};

t_stack			*new_stack(void);
t_stack			*stack_copy(t_stack *stack);
size_t			stack_size(t_stack *stack);
int				stack_push(t_stack *stack, int data);
void			stack_pop(t_stack *stack);
t_node_stack	*stack_last(t_stack *a);

#endif
