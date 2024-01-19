#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/***Direction macros for bitonic sort***/
#define ASC 0
#define DESC 1

/**
 * enum bool - Indicates the enumeration of boolean values
 * @false: This sets the value of the first enumeration constant false to 0
 * @true: Since enum constants are assigned values sequentially by default,
 *        true gets the value 1
*/

typedef enum bool
{
	false = 0,
	true
} bool;


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**  Function Prototypes **/
void swapInt(int *x, int *y);

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
