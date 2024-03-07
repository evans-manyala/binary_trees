#include "binary_trees.h"

/*
 * binary_tree_is_perfect - Function checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Description: Function checks if a binary tree is perfect
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height_left, height_right;

	if (!tree)
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	if (height_left == height_right)
	{
		if (!tree->left && !tree->right)
			return (1);

		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}

	return (0);
}

/**
 * binary_tree_height - Function measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
		return (0);
	l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return ((l > r) ? l : r);
	return (0);
}
