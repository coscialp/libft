/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hash_change_value.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/13 18:10:19 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 18:52:12 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_hash_change_value(t_hash *hash, char *key, void *value, char *type)
{
	t_hash	*add;
	t_hash	*top;
	short	free;

	top = hash->top;
	while (hash)
	{
		if (!ft_strcmp(hash->key, key))
		{
			if (hash->free)
				ft_memdel((void *)&hash->value);
			hash->value = value;
			return ;
		}
		hash = hash->next;
	}
	free = ft_strcmp(type, "string") != 0 ? 1 : 0;
	add = ft_hashnew(ft_strdup(key), value, free, type);
	hash = top;
	hash->add_back(&hash, add);
}
