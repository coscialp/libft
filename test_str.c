/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:02:59 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/19 21:32:29 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define	NITEM 20
#define SIZE 1024

typedef struct s_string
{
	char		*chain;
	long		value;
	size_t		size;
	char		touch;
	char		stack;
	char		heap;
	size_t		(*len)(struct s_string *);
	void		(*dup)(struct s_string *, char *);
	void		(*free)(struct s_string *);
	long		(*compare)(struct s_string, struct s_string);
	void		(*on_stack)(struct s_string *);
	void		(*on_heap)(struct s_string *, size_t size);
}				t_string;

void		ft_on_heap(t_string *str, size_t size)
{
	str->chain = malloc(size + 1);
	str->heap = 1;
	str->touch = 1;
}

void		ft_on_stack(t_string *str)
{
	static char	s[NITEM][SIZE];
	static int	i = 0;

	str->chain = (char *)&s[i];
	i++;
	str->stack = 1;
	if (i == NITEM)
		i = 0;
}

long		ft_compare(struct s_string s1, struct s_string s2)
{
	return (s1.value - s2.value);
}

long		ft_find_nbr(char *str, size_t *size)
{
	size_t	i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		nbr += str[i];
		i++;
	}
	*size = i;
	return (nbr);
}

void		ft_free(struct s_string *str)
{
	if (str->heap)
		ft_strdel(&str->chain);
	else if (str->stack)
		str->chain = NULL;
	str->value = 0;
	str->touch = 1;
	str->heap = 0;
	str->stack = 0;
}

void		ft_dup(struct s_string *str, char *new)
{
	size_t	size;


	str->value = ft_find_nbr(new, &str->size);
	str->on_heap(str, sizeof(char) * str->size);
	ft_strcpy(str->chain, new);
	str->touch = 0;
}

size_t		ft_len(struct s_string *str)
{
	if (str->size == 0 || str->touch == 1)
		str->size = ft_strlen(str->chain);
	str->touch = 0;
	return (str->size);
}

t_string	ft_str_init(void)
{
	t_string str = {NULL, 0, 0, 0, 0, 0, ft_len, ft_dup, ft_free, ft_compare, ft_on_stack, ft_on_heap};

	return (str);
}

int		main()
{
	t_string str = ft_str_init();
	t_string str2 = ft_str_init();
	t_string str3 = ft_str_init();

	str.dup(&str, "bonjour");
	str2.on_stack(&str2);
	str2.chain = "test";
	str3.on_stack(&str3);
	str3.chain = "lol";
	ft_printf("str1:%s\n", str.chain);
	ft_printf("str2:%s\n", str2.chain);
	ft_printf("str3:%s\n", str3.chain);
	ft_printf("str1:%u\n", str.len(&str));
	ft_printf("str1:%u\n", str.len(&str));
	ft_printf("str2:%u\n", str2.len(&str2));
	str.free(&str);
	str.dup(&str, "test");
	ft_printf("str1:%u\n", str.len(&str));
	ft_printf("dif:%d\n", str.compare(str, str2));
	str.free(&str);
	str.free(&str2);
	str.free(&str3);
}