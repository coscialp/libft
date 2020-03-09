/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_AVL.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:02:33 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/09 19:11:45 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

typedef struct	AVL
{
	int		item;
	size_t		height;
	struct AVL	*right;
	struct AVL	*left;
}				AVL;

AVL		*Node(int item)
{
	AVL *node;
	
	if (!(node = malloc(sizeof(*node))))
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->item = item;
	node->height = 1;
	return (node);
}

int		height(AVL *current)
{
	if (!current)
		return (0);
	return (current->height);
}

static int		Balance(AVL *current)
{
	if (!current)
		return (0);
	return (height(current->left) - height(current->right));
}

static int		max(int a, int b)
{
	return (a < b ? b : a);
}

static AVL		*rotate_right(AVL *y)
{
	AVL		*x;
	AVL		*T2 = NULL;

	x = y->left;
	if (x)
	{
		T2 = x->right;
		x->right = y;
	}
	y->left = T2;
	y->height = max(height(y->left), height(y->right)) + 1;
	if (x)
		x->height = max(height(x->left), height(x->right)) + 1;
	return (x);
}

static AVL		*rotate_left(AVL *x)
{
	AVL		*y;
	AVL		*T2 = NULL;

	y = x->right;
	if (y)
	{
		T2 = y->left;
		y->left = x;
	}
	x->right = T2;
	x->height = max(height(x->left), height(x->right)) + 1;
	if (y)
		y->height = max(height(y->left), height(y->right)) + 1;
	return (y);
}

static void		print_str(AVL *root)
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

void		debug(AVL *root)
{
	if (root->left)
		debug(root->left);
	print_str(root);
	if (root->right)
		debug(root->right);
}

AVL		*insert(AVL *current, int item)
{
	int	balance;

	if (!current)
		return (Node(item));
	if (current->item > item)
		current->left = insert(current->left, item);
	else
		current->right = insert(current->right, item);
	current->height = max(height(current->left), height(current->right)) + 1;
	balance = Balance(current);
	if (balance > 1 && item < current->left->item)
		return rotate_right(current);
	if (balance < -1 && item > current->right->item)
		return rotate_left(current);
	if (balance > 1 && item > current->left->item)
	{
		current->left = rotate_left(current->left);
		return rotate_right(current);
	}
	if (balance < -1 && item < current->right->item)
	{
		current->left = rotate_right(current->right);
		return rotate_left(current);
	}
	return (current);
}

int		main()
{
	AVL	*tree;

	tree = Node(10);
	tree = insert(tree, 4);
	tree = insert(tree, 1);
	tree = insert(tree, 19);
	tree = insert(tree, 11);
	tree = insert(tree, 12);
	debug(tree);
}