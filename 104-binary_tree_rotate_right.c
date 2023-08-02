#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer tot the root node of the tree
 *
 * Return: a pointer to the root node of the tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (!tree || !tree->left)
		return (tree);

	root = tree->left;
	if (!root->right)
		tree->left = NULL;
	else
	{
		tree->left = root->right;
		root->right->parent = tree;
	}

	root->right = tree;
	root->parent = tree->parent;
	tree->parent = root;

	return (root);
}
