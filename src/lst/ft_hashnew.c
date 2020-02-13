/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hashnew.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/13 13:33:26 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 18:52:15 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_hash		*ft_hashnew(char *key, void *value, short free, char *type)
{
	t_hash	*hash;

	if (!(hash = (t_hash *)malloc(sizeof(t_hash) * 1)))
		return (NULL);
	hash->key = key;
	hash->value = value;
	hash->top = hash;
	hash->next = NULL;
	hash->free = free;
	hash->type = type;
	hash->del = ft_hashdel;
	hash->print = ft_hash_display;
	hash->add_back = ft_hashadd_back;
	hash->add_front = ft_hashadd_front;
	hash->del_all = ft_hash_free;
	hash->search = ft_hash_search_value;
	hash->len = ft_hashlen;
	hash->change = ft_hash_change_value;
	return (hash);
}
