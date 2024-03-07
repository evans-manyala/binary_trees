#include "binary_trees.h"

/**
 * enqueue - Helper function that Enqueues a node in the queue.
 * @queue: The queue.
 * @rear: The rear index of the queue.
 * @size: The size of the queue.
 * @node: The node to enqueue.
 */
static void enqueue(binary_tree_t **queue, int *rear, int *size,
		    binary_tree_t *node)
{
	if (*rear >= *size)
	{
		*size *= 2;
		queue = realloc(queue, sizeof(binary_tree_t *) * (*size));
		if (queue == NULL)
		{
			free(queue);
			exit(EXIT_FAILURE);
		}
	}
	queue[(*rear)++] = node;
}

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
	int front = 0, rear = 0, size = 1;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *) * size);

	if (queue == NULL)
		return;

	enqueue(queue, &rear, &size, (binary_tree_t *)tree);

	/* Perform level-order traversal */
	while (front < rear)
	{
		binary_tree_t *current = queue[front];

		func(current->n);
		if (current->left != NULL)
			enqueue(queue, &rear, &size, current->left);
		if (current->right != NULL)
			enqueue(queue, &rear, &size, current->right);

		front++;
	}
	free(queue);
}
