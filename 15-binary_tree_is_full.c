#include "binary_trees.h"
/**
 * binary_tree_is_full - Function checks if binary tree is full
 * @node: Pointer to the root node of the tree to check
 * Return: 1 if full, 0 otherwise. If node is NULL, return 0.
 */
int binary_tree_is_full(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);
	else if (node->left != NULL && node->right != NULL)
		return (binary_tree_is_full(node->left) && binary_tree_is_full(node->right));
	return (0);
}
