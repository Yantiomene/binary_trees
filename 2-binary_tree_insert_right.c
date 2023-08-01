#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the parent node
 * @value: value to store in the new node
 *
 * Return: pointer to the created node or NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *temp;

	if (!parent)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (!node)
		return (NULL);
	if (!parent->right)
		parent->right = node;
	else
	{
		temp = parent->right;
		parent->right = node;
		temp->parent = node;
		node->right = temp;
	}

	return (node);
}
