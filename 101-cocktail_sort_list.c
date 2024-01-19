#include "sort.h"

/**
 * nodes_swap - Swap two nodes in a doubly linked list
 * @list: Address of the first node in the list
 * @first: Address of the first node to be swapped
 * @second: Address of the second node to be swapped
 */
void nodes_swap(listint_t **list, listint_t *first, listint_t *second)
{
    if (!first->prev)   /* at the first node */
        *list = second;
    else
        first->prev->next = second;

    second->prev = first->prev;

    if (second->next)   /* at the last node */
        second->next->prev = first;

    first->prev = second;
    first->next = second->next;
    second->next = first;
}

/**
 * cocktail_sort_list - Apply the cocktail sort algorithm to sort a list of numbers
 * @list: Address of the first node in the list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *future;
    int swapped = 1;

    if (!list || !(*list) || !(*list)->next)  /* only one node */
        return;

    future = *list;
    while (swapped)
    {
        swapped = 0;
        while (future->next)    /* traverse forward */
        {
            if (future->n > future->next->n)
            {
                nodes_swap(list, future, future->next);
                print_list(*list);
                swapped = 1;
                continue;
            }
            future = future->next;
        }

        if (!swapped)   /* list is sorted */
            break;

        swapped = 0;
        while (future->prev)    /* traverse backwards */
        {
            if (future->n < future->prev->n)
            {
                nodes_swap(list, future->prev, future);
                print_list(*list);
                swapped = 1;
                continue;
            }
            future = future->prev;
        }
    }
}

