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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root of the tree
 *
 * Return: 1 if true and 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);

	if (tree_height(tree->left) == tree_height(tree->right))
	{
		if (!tree->left)
			return (1);
		if (!(tree->left)->left && !(tree->left)->right)
			return (1);
		if (tree->left && tree->right)
		{
			l = binary_tree_is_perfect(tree->left);
			r = binary_tree_is_perfect(tree->right);
			return (l && r);
		}
	}
	return (0);
}
