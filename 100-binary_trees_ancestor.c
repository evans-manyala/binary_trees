#include "binary_trees.h"

/**
 * binary_trees_ancestor - Function checks the LCA of two nodes
 *
 * @first: Pointer to the 1st node
 * @second: Pointer to the 2nd node
 *
 * Return: Lowest ancestor, otherwise NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *temp;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	while (first)
	{
		temp = second;

		while (temp)
		{
			if (first == temp)
				return ((binary_tree_t *)first);

			temp = temp->parent;
		}

		first = first->parent;
	}
	return (NULL);
}
