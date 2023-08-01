#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: is the pointer to the node
 *
 * Return: the pointer to the sibling or null
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (!node || !node->parent)
		return (NULL);
	parent = node->parent;

	if (parent->left && parent->left == node)
		return (parent->right);
	return (parent->left);
}
