#include "binary_trees.h"

/**
 * max_left - finds the maximum value in the left of a node
 * @node: pointer to the node
 *
 * Return: the maximum left value
 */
int max_left(const binary_tree_t *node)
{
	int value, l_max, r_max;

	if (!node)
		return (INT_MIN);

	l_max = max_left(node->left);
	r_max = max_left(node->right);

	if (l_max > r_max)
		value = l_max;
	else
		value = r_max;
	if (value < node->n)
		value = node->n;

	return (value);
}


/**
 * min_right - finds the minimum value in the right of a node
 * @node: pointer to the node;
 *
 * Return: the min value
 */
int min_right(const binary_tree_t *node)
{
	int value, l_min, r_min;

	if (!node)
		return (INT_MAX);

	l_min = min_right(node->left);
	r_min = min_right(node->right);

	if (l_min < r_min)
		value = l_min;
	else
		value = r_min;
	if (value > node->n)
		value = node->n;

	return (value);
}

/**
 * is_bst -  checks if a binary tree is a bst
 * @node: pointer to the root node
 *
 * Return: 1 if true and 0 if not
 */
int is_bst(const binary_tree_t *node)
{
	if (!node)
		return (1);
	if (node->left && max_left(node->left) >= node->n)
		return (0);
	if (node->right && min_right(node->right) <= node->n)
		return (0);

	return (is_bst(node->left) && is_bst(node->right));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a bst
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if true or 0 ortherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst(tree));
}
