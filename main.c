/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:24:16 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/17 19:37:32 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     main(int ac, char **av, char **environ)
{
    size_t  i = 1;
    t_hash  *hash;
    t_hash  *env;
    t_hash  *add;
    t_hash  *top;
    // t_hash  *env;

    hash = ft_hash_init();
    env = hash->new("first", "1", "string");
    add = hash->new("second", "2", "string");
    env->add_back(&env, add);
    // add = hash->new("third", "3", "string");
    // env->add_back(&env, add);
    top = env;
    // while (environ[i])
    // {
    //     add = hash->new(ft_strtok(environ[i], "="), ft_strtok(NULL, "="), "string");
    //     env->add_back(&env, add);
    //     i++;
    // }
    // env->print(env, "env");

    while (env)
    { 
        ft_dprintf(1, "%-20s=%-20sadress:%p\ttop:%p\tbefore:%p\tnext:%p\n\n", env->key, env->value, env, env->top, env->before, env->next);
        env = env->next;
    }
    env = top;
    // env->len(&env);
    // env = top;
    // env->print(env, "env");
    // env = top;
    env->del_all(&env);
    // ft_dprintf(1, "%p\n", env);
}