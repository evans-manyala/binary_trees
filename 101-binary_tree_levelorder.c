#include "binary_trees.h"
/**
 * binary_tree_levelorder - Function traverses a binary tree via level-order traversal
 * @tree: pointer to the root node of the tree being traversed.
 * @func: pointer to a function to call for each node.
 * If tree or func is NULL, do nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
	if (queue == NULL)
		return;

	int front = 0, rear = 0;
	queue[rear++] = (binary_tree_t *)tree;

	/* Perform level-order traversal */
	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		func(current->n);
		if (current->left)
			queue[rear++] = current->left;
		if (current->right)
			queue[rear++] = current->right;
	}
	free(queue);
}
