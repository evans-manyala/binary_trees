#include "binary_trees.h"

/**
 * array_to_bst - Converts an array of integers into a Binary Search Tree (BST).
 * @array: The array of integers to be converted.
 * @size: The size of the array.
 * Return: A pointer to the root node of the BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	bst_t *tree = NULL;
	for (size_t i = 0; i < size; i++)
	{
		bst_insert(&tree, array[i]);
	}
	return (tree);
}
