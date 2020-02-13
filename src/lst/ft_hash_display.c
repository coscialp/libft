/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hash_display.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/13 16:59:24 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 17:52:36 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_hash_display(t_hash *hash)
{
	while (hash)
	{
		if (!ft_strcmp(hash->type, "string"))
			ft_printf("hash[%s]=%s\n", hash->key, hash->value);
		else if (!ft_strcmp(hash->type, "int"))
			ft_printf("hash[%s]=%d\n", hash->key, hash->value);
		else if (!ft_strcmp(hash->type, "char"))
			ft_printf("hash[%s]=%c\n", hash->key, hash->value);
		else if (!ft_strcmp(hash->type, "float"))
			ft_printf("hash[%s]=%f\n", hash->key, hash->value);
		hash = hash->next;
	}
}
