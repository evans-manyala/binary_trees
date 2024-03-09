#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 *
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 *
 * Description:
 * - If the address stored in tree is NULL, the created node must become the root node.
 * - If the value is already present in the tree, it must be ignored.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
	{
		return (NULL);
	}

	if (*tree == NULL)
	{
		bst_t *new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}

	bst_t *current_node = *tree;
	while (1)
	{
		if (value < current_node->n)
		{
			if (current_node->left == NULL)
			{
				bst_t *new_node = binary_tree_node(current_node, value);
				current_node->left = new_node;
				return (new_node);
			}
			current_node = current_node->left;
		}
		else if (value > current_node->n)
		{
			if (current_node->right == NULL)
			{
				bst_t *new_node = binary_tree_node(current_node, value);
				current_node->right = new_node;
				return (new_node);
			}
			current_node = current_node->right;
		}
		else
			return (NULL);
	}
}
