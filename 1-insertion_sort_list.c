#include "sort.h"

/**
 * swap - Swap nodes on list.
 * @list: pointer to head of list.
 * @current: pointer to current node of list.
 * @previous: pointer to previous node of list.
 */
void swap(listint_t **list, listint_t *current, listint_t *previous)
{
	if (current->next)
		(current->next)->prev = previous;

	current->prev = previous->prev;
	current->next = previous;

	if (previous->prev)
		(previous->prev)->next = current;
	else
		(*list) = current;
}

/**
 * insertion_sort_list - Sort a list with insertion sort algorithm.
 * @list: list of integers
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *previous = NULL, *current = NULL, *next = NULL;

	if (!list || !(*list))
		return;

	current = (*list)->next;
	while (current)
	{
		next = current->next;
		previous = current->prev;

		while (previous && current->n < previous->n)
		{
			previous->next = current->next;

			swap(list, current, previous);
			previous->prev = current;
			previous = current->prev;

			print_list(*list);
		}
		current = next;
	}
}
