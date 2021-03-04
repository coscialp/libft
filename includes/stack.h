/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:02:25 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 15:24:11 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct s_node_stack	t_node_stack;
struct s_node_stack
{
	int				value;
	t_node_stack	*_next;
	t_node_stack	*_prev;
};

typedef struct s_stack		t_stack;
struct s_stack
{
	t_node_stack	*_data;
	size_t			_size;
	void			(*push)(t_stack *, int);
	void			(*pop)(t_stack *);
	size_t			(*size)(t_stack *);
};

t_stack	new_stack(void);
size_t	stack_size(t_stack *stack);
void	stack_push(t_stack *stack, int data);
void	stack_pop(t_stack *stack);

#endif