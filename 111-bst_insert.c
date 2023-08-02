#include "binary_trees.h"


/**
 * ins_bst - insert in bst
 * @tree: double pointer to the binary tree
 * @value: value to be inserted
 *
 * Return: pointer to the inserted node
 */
bst_t *ins_bst(bst_t **tree, int value)
{
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		return (ins_bst(&((*tree)->left), value));
	}
	if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		return (ins_bst(&((*tree)->right), value));
	}

	return (NULL);
}

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST
 * @value: value to store
 *
 * Return: pointer to the creatd node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	return (ins_bst(tree, value));
}
