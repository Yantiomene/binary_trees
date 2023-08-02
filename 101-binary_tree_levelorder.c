#include "binary_trees.h"

/**
 * get_height - recursively calculate the height
 * @root: pointer to the root node
 *
 * Return: the heigh of the tree
 */
size_t get_height(const binary_tree_t *root)
{
	size_t h_l, h_r;

	if (!root)
		return (0);
	h_l = h_r = 0;

	h_l = get_height(root->left);
	h_r = get_height(root->right);

	if (h_l > h_r)
		return (h_l + 1);
	return (h_r + 1);
}

/**
 * traverse_level - traverse the level and execute the function on each node
 * @tree: pointer to the root node
 * @lev: current level
 * @func: pointer function to execute on each node
 *
 * Return: nothing
 */
void traverse_level(const binary_tree_t *tree, int lev, void (*func)(int))
{
	if (lev == 1)
		func(tree->n);
	else if (lev > 1)
	{
		traverse_level(tree->left, lev - 1, func);
		traverse_level(tree->right, lev - 1, func);
	}
}

/**
 * binary_tree_levelorder - traverse a binary tree suning level-order traversal
 * @tree: pointer to the root of the node
 * @func: function pointer to call on each node
 *
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (!tree || !func)
		return;
	h = get_height(tree);

	for (i = 1; i <= h; i++)
		traverse_level(tree, i, func);
}
