/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hash_display.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/13 16:59:24 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 09:57:00 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_hash_display(t_hash *hash, char *name)
{
	while (hash)
	{
		ft_printf("%s[%s]=%s\n", name, hash->key, hash->value);
		hash = hash->next;
	}
}
