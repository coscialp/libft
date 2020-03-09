/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:13:39 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/09 18:02:11 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define	STR 0
#define INT 1

typedef struct	s_bstree
{
	void				*item;
	int					*height;
	struct s_bstree		*right;
	struct s_bstree		*left;
	void				(*add)(struct s_bstree **, void *);
	void				(*display)(struct s_bstree *);
	void				(*debug)(struct s_bstree *);
	void				*(*search)(struct s_bstree *, void *);
	int					(*size)(struct s_bstree *);
	int					(*size_right)(struct s_bstree *);
	int					(*size_left)(struct s_bstree *);
}				t_bstree;

t_bstree	*bstree(void *item, char type);

static void		print_str(t_bstree *root)
{
	if (root->left)
		ft_dprintf(1, "%12s <--- ", root->left->item);
	else
		ft_dprintf(1, "%12s <--- ", root->left);
	ft_dprintf(1, "%-8s ---> ", root->item);
		if (root->right)
		ft_dprintf(1, "%12s\n", root->right->item);
	else
		ft_dprintf(1, "%12s\n", root->right);
}

static void		print_int(t_bstree *root)
{
	if (root->left)
		ft_dprintf(1, "%12d <--- ", root->left->item);
	else
		ft_dprintf(1, "%12s <--- ", root->left);
	ft_dprintf(1, "%-8d ---> ", root->item);
		if (root->right)
		ft_dprintf(1, "%12d\n", root->right->item);
	else
		ft_dprintf(1, "%12s\n", root->right);
}

void		debug_tree_str(t_bstree *root)
{
	if (root->left)
		debug_tree_str(root->left);
	print_str(root);
	if (root->right)
		debug_tree_str(root->right);
}

void		debug_tree_int(t_bstree *root)
{
	if (root->left)
		debug_tree_int(root->left);
	print_int(root);
	if (root->right)
		debug_tree_int(root->right);
}

void		display_tree_str(t_bstree *root)
{
	if (root->left)
		display_tree_str(root->left);
	ft_dprintf(1, "%s\n", root->item);
	if (root->right)
		display_tree_str(root->right);
}

void		display_tree_int(t_bstree *root)
{
	if (root->left)
		display_tree_int(root->left);
	ft_dprintf(1, "%d\n", root->item);
	if (root->right)
		display_tree_int(root->right);
}

void		*search_data_str(t_bstree *root, void *data_ref)
{
	void	*out;

	out = NULL;
	if (root)
	{
		out = search_data_str(root->left, data_ref);
		if (!out && !ft_strcmp(root->item, data_ref))
			out = root;
		if (!out)
			out = search_data_str(root->right, data_ref);
	}
	return (out);
}

void		*search_data_int(t_bstree *root, void *data_ref)
{
	void	*out;

	out = NULL;
	if (root)
	{
		out = search_data_int(root->left, data_ref);
		if (!out && root->item == data_ref)
			out = root;
		if (!out)
			out = search_data_int(root->right, data_ref);
	}
	return (out);
}

int	max(int a, int b)
{
	return (a > b ? a : b);
}

int		level_count(t_bstree *root)
{
	if (root)
		return (1 + max(level_count(root->left), level_count(root->right)));
	return (0);
}

int			size_right(t_bstree *root)
{
	if (root)
		return (1 + size_right(root->right));
	return (0);
}

int			size_left(t_bstree *root)
{
	if (root)
		return (1 + size_left(root->left));
	return (0);
}

int			count_nodes(t_bstree *root)
{
	if (root)
		return (1 + count_nodes(root->left) + count_nodes(root->right));
	return (0);
}

void		insert_node_nbr(t_bstree **root, void *item)
{
	t_bstree	*current;
	
	current = *root;
	if (item - current->item < 0)
	{
		if (current->left)
			insert_node_nbr(&current->left, item);
		else
			current->left = bstree(item, INT);
	}
	else
	{
		if (current->right)
			insert_node_nbr(&current->right, item);
		else
			current->right = bstree(item, INT);
	}
}

void		insert_node_str(t_bstree **root, void *item)
{
	t_bstree	*current;
	
	current = *root;
	if (ft_strcmp(item, current->item) < 0)
	{
		if (current->left)
			insert_node_str(&current->left, item);
		else
			current->left = bstree(item, STR);
	}
	else
	{
		if (current->right)
			insert_node_str(&current->right, item);
		else
			current->right = bstree(item, STR);
	}
}

t_bstree	*bstree(void *item, char type)
{
	t_bstree	*node;

	if (!(node = malloc(sizeof(*node))))
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->item = item;
	node->height = 1;
	node->size = count_nodes;
	node->size_right = size_right;
	node->size_left = size_left;
	if (type == INT)
	{
		node->add = insert_node_nbr;
		node->display = display_tree_int;
		node->debug = debug_tree_int;
		node->search = search_data_int;
	}
	if (type == STR)
	{
		node->add = insert_node_str;
		node->display = display_tree_str;
		node->search = search_data_str;
		node->debug = debug_tree_str;
	}
	return (node);
}

int		main()
{
	t_bstree	*tmp;
	t_bstree	*tree;
	void		*data;
	
	tree = bstree((void *)10, INT);
	tree->add(&tree, (void *)8);
	tree->add(&tree, (void *)13);
	tree->add(&tree, (void *)5);
	tree->add(&tree, (void *)7);
	tree->debug(tree);
}