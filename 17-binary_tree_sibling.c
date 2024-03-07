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
		return (NULL);
	;
	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
