#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_is_complete - Function tests if a binary tree is complete.
 * @tree: The root of the binary tree.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int non_full_node = 0;
	int front = 0, rear = 0;
	binary_tree_t **queue;

	if (tree == NULL)
		return (0);

	/* Create a queue for level order traversal */
	queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));

	/* Enqueue the root and start level order traversal */
	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		if (current == NULL)
			non_full_node = 1;
		else if (non_full_node)
			return (0);
		if (current->left)
			queue[rear++] = current->left;
		if (current->right)
			queue[rear++] = current->right;
	}
	free(queue);
	return (1);
}
