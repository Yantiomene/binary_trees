#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node
 * @tree: pointer to the node
 *
 * Return: the depth of the node or 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *parent;
	size_t depth = 0;

	if (!tree)
		return (0);

	parent = tree->parent;
	while (parent)
	{
		depth++;
		parent = parent->parent;
	}

	return (depth);
}
