#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the parent node
 * @value: value to store in the new node
 *
 * Return: pointer to the created node or NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *temp;

	if (!parent)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (!node)
		return (NULL);
	if (!parent->left)
		parent->left = node;
	else
	{
		temp = parent->left;
		parent->left = node;
		temp->parent = node;
		node->left = temp;
	}

	return (node);
}
