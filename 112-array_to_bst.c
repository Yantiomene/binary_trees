#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search tree from an array
 * @array: pointer to the array
 * @size: number of element in the arrray
 *
 * Return: the pointer to the root node of the BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i;

	if (!array || size == 0)
		return (NULL);
	root = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	if (i == size)
		return (root);
	return (NULL);
}
