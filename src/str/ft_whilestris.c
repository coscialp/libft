/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whilestris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:57:40 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/17 13:02:28 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_whilestris(char *str, int *i, int (*f)(int), char neg)
{
	if (str && neg == 0)
		while (str[*i] && (*f)(str[*i]))
			*i += 1;
	else if (str && neg == 1)
		while (str[*i] && !(*f)(str[*i]))
			*i += 1;
}
