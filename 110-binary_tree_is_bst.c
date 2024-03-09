#include "binary_trees.h"

/**
 * is_bst_util - Helper function to recursively
 * check if a binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree.
 * @min: Minimum value for the current subtree.
 * @max: Maximum value for the current subtree.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return ((is_bst_util(tree->left, min, tree->n) &&
		 is_bst_util(tree->right, tree->n, max)));
}

/**
 * binary_tree_is_bst - Checks if a binary tree
 * is a valid Binary Search Tree (BST).
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 *         If tree is NULL, return 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_util(tree, INT_MIN, INT_MAX));
}
