#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root nod of the tree
 *
 * Return: the size or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);
	size = 1 + binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size);
}

/**
 * is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node
 * @index: index of the node
 * @n_node: number of node of the tree
 *
 * Return: 1 if true or 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t n_node)
{
	if (!tree)
		return (1);
	if (index >= n_node)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, n_node) &&
		is_complete(tree->right, 2 * index + 2, n_node));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node
 *
 * Return: 1 if true or 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t index, n_node;

	if (!tree)
		return (0);
	index = 0;
	n_node = binary_tree_size(tree);

	return (is_complete(tree, index, n_node));
}
