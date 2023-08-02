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

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: the pointer to the ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t d_f, d_s;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	d_f = binary_tree_depth(first);
	d_s = binary_tree_depth(second);

	if (d_f > d_s)
		return (binary_trees_ancestor(first->parent, second));
	if (d_f < d_s)
		return (binary_trees_ancestor(first, second->parent));

	return (binary_trees_ancestor(first->parent, second->parent));
}
