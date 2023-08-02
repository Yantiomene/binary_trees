#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer tot the root node of the tree
 *
 * Return: a pointer to the root node of the tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (!tree || !tree->right)
		return (tree);

	root = tree->right;
	if (!root->left)
		tree->right = NULL;
	else
	{
		tree->right = root->left;
		root->left->parent = tree;
	}

	root->left = tree;
	root->parent = tree->parent;
	tree->parent = root;

	return (root);
}
