#include "binary_trees.h"
/**
 * binary_tree_sibling - Function that finds the sibling of a node
 * @node: Pointer to the node to check
 *
 * Return: node that is a subling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL); // Handle NULL node or parent cases

	// Check if the node is the left or right child of its parent
	if (node->parent->left == node)
		return (node->parent->right); // Sibling is the right child
	else
		return (node->parent->left); // Sibling is the left child
}
