/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_limit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:19:21 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/11 10:34:31 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline size_t	st_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

inline size_t	st_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}
