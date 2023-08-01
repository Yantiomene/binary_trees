#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least a child
 * @tree: pointer to the root of the tree
 *
 * Return: the number of parent nodes or 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);
	if (tree->left || tree->right)
		count++;

	count += binary_tree_nodes(tree->left);
	count += binary_tree_nodes(tree->right);

	return (count);
}
