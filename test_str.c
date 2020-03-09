/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_str.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/19 16:02:59 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/21 11:41:05 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "libft.h"

#define	NITEM 20
#define SIZE 1024

typedef struct s_string
{
	char				*chain;
	long				value;
	size_t				size;
	char				touch;
	char				stack;
	char				heap;
	size_t				(*len)(struct s_string *);
	void				(*cpy)(struct s_string *, char *);
	void				(*move)(struct s_string *, char *);
	void				(*dup)(struct s_string *, char *);
	void				(*join)(struct s_string *, char *);
	struct s_string		*(*split)(struct s_string, char);
	void				(*free)(struct s_string *);
	void				(*free_tab)(struct s_string *);
	long				(*compare)(struct s_string *, struct s_string *);
	void				(*on_stack)(struct s_string *);
	void				(*on_heap)(struct s_string *, size_t size);
}				t_string;

t_string	ft_init_string(void);

t_string		*ft_split_string(t_string str, char c)
{
	t_string	*splited;
	size_t		i;
	size_t		size;
	char		**split;

	i = 0;
	split = ft_split(str.chain, c);
	while (split[i])
		i++;
	splited = malloc(sizeof(t_string) * (i + 1));
	size = (i + 1);
	i = 0;
	while (i < size)
		splited[i++] = ft_init_string();
	i = 0;
	while (split[i])
	{
		splited[i].dup(&splited[i], split[i]);
		i++;
	}
	ft_free_tab(split);
	return (splited);
}

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

long		ft_find_nbr(char *str, size_t *size)
{
	size_t	i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		nbr += (str[i] * (i + 1));
		i++;
	}
	*size = i;
	return (nbr);
}

void		ft_join(struct s_string *s1, char *s2)
{
	if (s1->stack)
		s1->chain = ft_strcat(s1->chain, s2);
	else if (s1->heap)
		s1->chain = ft_strfjoin(s1->chain, s2, 1);
	s1->touch = 1;
}

long		ft_compare(struct s_string *s1, struct s_string *s2)
{
	if (s1->touch == 1)
		s1->value = ft_find_nbr(s1->chain, &s1->size);
	if (s2->touch == 1)
		s2->value = ft_find_nbr(s2->chain, &s2->size);
	return (s1->value - s2->value);
}

void		ft_free_split(struct s_string *str)
{
	size_t	i;

	i = 0;
	while (str[i].chain)
	{
		str[i].free(&str[i]);
		i++;
	}
	ft_memdel((void *)&str);
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

void		ft_move_point(t_string *str, char *new)
{
	str->free(str);
	str->chain = new;
	str->touch = 1;
}

void		ft_cpy(t_string *str, char *new)
{
	ft_strcpy(str->chain, new);
	str->value = ft_find_nbr(str->chain, &str->size);
	str->touch = 0;
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
		str->value = ft_find_nbr(str->chain, &str->size);
	str->touch = 0;
	return (str->size);
}

t_string	ft_init_string(void)
{
	t_string str = {NULL, 0, 0, 0, 0, 0, ft_len, ft_cpy, ft_move_point, ft_dup, ft_join, ft_split_string, ft_free, ft_free_split, ft_compare, ft_on_stack, ft_on_heap};

	return (str);
}

int		main()
{
	t_string	str = ft_init_string();
	t_string	str2 = ft_init_string();
	t_string	str3 = ft_init_string();
	t_string	*split;

	str.dup(&str, "bonjour je mappelle john");
	str2.on_stack(&str2);
	str2.cpy(&str2, "zb");
	str3.on_stack(&str3);
	str3.move(&str3, "lol");
	ft_printf("str1:%s\n", str.chain);
	ft_printf("str2:%s\n", str2.chain);
	ft_printf("str1.len:%u\n", str.len(&str));
	ft_printf("str2.len:%u\n", str2.len(&str2));
	str2.join(&str2, str3.chain);
	split = str.split(str, ' ');
	ft_printf("str1:%s\n", str.chain);
	ft_printf("str2:%s\n", str2.chain);
	ft_printf("str1.len:%u\n", str.len(&str));
	ft_printf("dif:%d\n", str.compare(&str, &str2));
	for (int i = 0; split[i].chain; i++)
		ft_printf("split[%d]=%s\n", i, split[i].chain);
	str.free(&str);
	str.free(&str2);
	str.free(&str3);
	split->free_tab(split);
}