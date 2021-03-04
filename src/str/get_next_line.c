/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:50:03 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/04 10:29:57 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*next_line(char *str, char **line, size_t i, int *end)
{
	char			*tmp;

	if (str && str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n')
		{
			*line = ft_substr(str, 0, i);
			tmp = ft_strdup(str + i + 1);
			ft_strcpy(str, tmp);
			ft_strdel(&tmp);
			return (*line);
		}
		else
		{
			*line = ft_substr(str, 0, i);
			tmp = ft_strdup(str + i);
			ft_strcpy(str, tmp);
			ft_strdel(&tmp);
			return (*line);
		}
	}
	*end = 1;
	return (NULL);
}

char	*read_line(char **str, char *buf, int fd)
{
	int				ret;
	char			*tmp;

	ret = read(fd, buf, BUFFER_SIZE);
	while (ret != 0)
	{
		if (ret < 0)
			return ((char *) - 1);
		if (!str[fd])
		{
			str[fd] = ft_strdup("");
			if (!str[fd])
				return ((char *) - 1);
		}
		buf[ret] = '\0';
		tmp = ft_strfjoin(str[fd], buf, 1);
		if (!tmp)
			return ((char *) - 1);
		str[fd] = tmp;
		if (ft_strchr(str[fd], '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	return (str[fd]);
}

int	get_next_line(int fd, char **line)
{
	int				end;
	static char		*str[256];
	char			buf[BUFFER_SIZE + 1];

	end = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || fd >= 256)
	{
		if (*line)
			*line = NULL;
		return (-1);
	}
	str[fd] = read_line(str, buf, fd);
	if (str[fd] == (char *) - 1)
	{
		if (*line)
			*line = NULL;
		return (-1);
	}
	*line = next_line(str[fd], line, 0, &end);
	if (end == 1)
		ft_strdel(&str[fd]);
	return (end != 1);
}
