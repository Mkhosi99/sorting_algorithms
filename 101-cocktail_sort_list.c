#include "sort.h"

void swap_ndeNext(listint_t **list, listint_t **end, listint_t **shake);
void swap_ndePrev(listint_t **list, listint_t **end, listint_t **shake);
void cocktail_sort_list(listint_t **list);

/**
 * swap_ndeNext - Swaps a node in listint_t doubly-linked list
 *                list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @end: A pointer to the tail of the doubly-linked list.
 * @shake: A pointer to the current swapping node of the cocktail shaker algo.
 */


void swap_ndeNext(listint_t **list, listint_t **end, listint_t **shake)
{
	listint_t *tempo = (*shake)->next;

	if ((*shake)->prev != NULL)
		(*shake)->prev->next = tempo;
	else
		*list = tempo;
	tempo->prev = (*shake)->prev;
	(*shake)->next = tempo->next;
	if (tempo->next != NULL)
		tempo->next->prev = *shake;
	else
		*end = *shake;
	(*shake)->prev = tempo;
	tempo->next = *shake;
	*shake = tempo;
}

/**
 * swap_ndePrev - Swaps a node in listint_t doubly-linked
 *                list of integers with the node behind it.
 * @list: A pointer to the head of doubly-linked list
 * @end: A pointer to the tail of doubly-linked list
 * @shake: A pointer to the current swapping node of the cocktail shaker algo.
 */

void swap_ndePrev(listint_t **list, listint_t **end, listint_t **shake)
{
	listint_t *tempo = (*shake)->prev;

	if ((*shake)->next != NULL)
		(*shake)->next->prev = tempo;
	else
		*end = tempo;
	tempo->next = (*shake)->next;
	(*shake)->prev = tempo->prev;
	if (tempo->prev != NULL)
		tempo->prev->next = *shake;
	else
		*list = *shake;
	(*shake)->next = tempo;
	tempo->prev = *shake;
	*shake = tempo;
}

/**
 * cocktail_sort_list - Sorts a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of listint_t doubly-linked list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *end, *shake;
	bool swapped = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (end = *list; end->next != NULL;)
		end = end->next;

	while (swapped == false)
	{
		swapped = true;
		for (shake = *list; shake != end; shake = shake->next)
		{
			if (shake->n > shake->next->n)
			{
				swap_ndeNext(list, &end, &shake);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
		for (shake = shake->prev; shake != *list;
				shake = shake->prev)
		{
			if (shake->n < shake->prev->n)
			{
				swap_ndePrev(list, &end, &shake);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
	}
}
