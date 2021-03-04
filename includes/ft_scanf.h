/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:42:48 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 10:19:30 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCANF_H
# define FT_SCANF_H

# include "libft.h"
# include "libftprintf.h"
# define SUCESS 1
# define FAILURE -1

typedef struct s_scanf
{
	char		option;
	char		end_arg;
	char		*arg;
	char		*current_arg;
	size_t		return_size;
}				t_scanf;

int				ft_scanf(char *fmt, ...);
int				convert_s(t_scanf *sf, char **str);
int				convert_di(t_scanf *sf, int *nb);
int				apply_convert(t_scanf *sf, va_list ap);
int				read_stdin(char **line);

#endif
