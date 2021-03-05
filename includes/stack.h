/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:02:25 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/05 09:05:43 by akerdeka         ###   ########lyon.fr   */
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
	int				(*push)(t_stack *, int);
	void			(*pop)(t_stack *);
	size_t			(*size)(t_stack *);
};

t_stack	new_stack(void);
size_t	stack_size(t_stack *stack);
int		stack_push(t_stack *stack, int data);
void	stack_pop(t_stack *stack);

struct push_swap
{
	t_stack			stack_a;
	t_stack			stack_b;
	void			(*swap_a)(t_stack *);
	void			(*swap_b)(t_stack *);
	void			(*swap_s)(t_stack *, t_stack *);
	void			(*push_a)();
	void			(*push_b)();
};

#endif
