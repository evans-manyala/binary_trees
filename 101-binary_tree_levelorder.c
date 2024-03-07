#include "binary_trees.h"
/**
 * binary_tree_levelorder - Function traverses a binary tree
 * via level-order traversal
 * @tree: pointer to the root node of the tree being traversed.
 * @func: pointer to a function to call for each node.
 * If tree or func is NULL, do nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	int front, rear;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *));
	front = 0;
	rear = 1;

	queue[0] = (binary_tree_t *)tree;

	/* Perform level-order traversal */
	while (front < rear)
	{
		binary_tree_t *current = queue[front];

		func(current->n);
		if (current->left != NULL)
		{
			queue = realloc(queue, sizeof(binary_tree_t *) * (rear++));
			queue[rear++] = current->left;
		}
		if (current->right != NULL)
		{
			queue = realloc(queue, sizeof(binary_tree_t *) * (rear++));
			queue[rear++] = current->right;
		}
		front++;
	}
	free(queue);
}
