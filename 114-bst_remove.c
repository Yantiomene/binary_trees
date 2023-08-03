#include "binary_trees.h"

/**
 * bst_search - searches for a value in a BST
 * @tree: pointer to the root node
 * @value: value to search
 *
 * Return: pointer to the node containing value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	if (value > tree->n)
		return (bst_search(tree->right, value));

	return (NULL);
}

/**
 * binary_tree_is_leaf - ckecks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if true and 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->left && !node->right)
		return (1);
	return (0);
}

/**
 * case_node_has_rl - removes node in case it has right and right has left node
 * @root: pointer to the root node
 * @node: pointer to the node to delete
 *
 * Return: pointer to the root node
 */
bst_t *case_node_has_rl(bst_t *root, bst_t *node)
{
	node->right->left->right = node->right;
	node->right->left->parent = node->parent;
	node->right->left->left = node->left;

	if (node->left)
		node->left->parent = node->right->left;
	node->right->parent = node->right->left;
	if (root == node)
		root = node->right->left;
	else
	{
		if (node == node->parent->left)
			node->parent->left = node->right->left;
		if (node == node->parent->right)
			node->parent->right = node->right->left;
	}
	node->right->left = NULL;
	free(node);
	return (root);
}

/**
 * case_node_has_r - removes node in case it has a right node
 * @root: pointer to the root node
 * @node: pointer to the node
 *
 * Return: the pointer to the root node
 */
bst_t *case_node_has_r(bst_t *root, bst_t *node)
{
	node->right->left = node->left;
	node->right->parent = node->parent;
	if (node->parent)
	{
		if (node == node->parent->left)
			node->parent->left = node->right;
		if (node == node->parent->right)
			node->parent->right = node->right;
	}
	if (node->left)
		node->left->parent = node->right;
	if (root == node)
		root = node->right;
	free(node);
	return (root);
}

/**
 * bst_remove - removes a node from a BST
 * @root: pointer to the root node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	node = bst_search(root, value);

	if (node)
	{
		if (binary_tree_is_leaf(node) == 1)
		{
			if (node == node->parent->left)
				node->parent->left = NULL;
			if (node == node->parent->right)
				node->parent->right = NULL;
			free(node);
			return (root);
		}
		if (node->right && node->right->left)
			root = case_node_has_rl(root, node);
		else if (node->right)
			root = case_node_has_r(root, node);
		else
		{
			if (node->parent)
				node->parent->right = node->left;
			node->left->parent = node->parent;
			if (node == root)
				root = node->left;
			free(node);
		}
	}
	return (root);
}
