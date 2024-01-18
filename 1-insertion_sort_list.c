#include "sort.h"

/**
 * swapNdes - Function swaps two nodes in listint_t doubly-linked list.
 * @head: pointer to the head of the doubly-linked list.
 * @nde1: pointer to the first node to swap.
 * @nde2: second node to swap.
 */

void swapNdes(listint_t **head, listint_t **nde1, listint_t *nde2)
{
	(*nde1)->next = nde2->next;
	if (nde2->next != NULL)
		nde2->next->prev = *nde1;
	nde2->prev = (*nde1)->prev;
	nde2->next = *nde1;
	if ((*nde1)->prev != NULL)
		(*nde1)->prev->next = nde2;
	else
		*head = nde2;
	(*nde1)->prev = nde2;
	*nde1 = nde2->prev;
}

/**
 * insertion_sort_list - Function sorts a doubly linked list of
 *                       integers in ascending order
 * @list: pointer to the head of the doubly linked list
 * Time Complexity: O(n^2)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterate, *place, *tempo;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterate = (*list)->next; iterate != NULL; iterate = tempo)
	{
		tempo = iterate->next;
		place = iterate->prev;
		while (place != NULL && iterate->n < place->n)
		{
			swapNdes(list, &place, iterate);
			print_list((const listint_t *)*list);
		}
	}
}
