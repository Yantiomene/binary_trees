#include "binary_trees.h"

/**
 * binary_tree_delete - deletes the entire dinary tree
 * @tree: pointer to the root node ot the tree to delete
 *
 * Return: nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	free(tree);
}
