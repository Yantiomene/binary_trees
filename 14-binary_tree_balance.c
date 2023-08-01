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
 * tree_height - measures the height of a binary tree
 * @tree: the pointer to the root node of the tree
 *
 * Return: the height or 0
 */
size_t tree_height(const binary_tree_t *tree)
{

	if (!tree)
		return (-1);

	return (get_height(tree) - 1);
}

/**
 * binary_tree_balance - measures the balance factor of a bianry tree
 * @tree: pointer tot the root node of the tree
 *
 * Return: the balance factor or 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t m, n;

	if (!tree)
		return (0);
	m = tree_height(tree->left);
	n = tree_height(tree->right);

	return (m - n);
}
