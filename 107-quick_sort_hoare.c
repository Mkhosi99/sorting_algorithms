#include "sort.h"

void swapInt(int *x, int *y);
int hoare_partScheme(int *arr, size_t sze, int low, int high);
void hoareSorting(int *arr, size_t sze, int low, int high);

/**
 * swapInt - Function swaps two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */

void swapInt(int *x, int *y)
{
	int tempo;

	tempo = *x;
	*x = *y;
	*y = tempo;
}

/**
 * hoare_partScheme - Will order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @arr: The array of integers.
 * @sze: The size of the array.
 * @low: The starting index of the subset to be ordered.
 * @high: The ending index of the subset to be ordered.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partScheme(int *arr, size_t sze, int low, int high)
{
	int piv, top, under;

	piv = arr[high];
	for (top = low - 1, under = high + 1; top < under;)
	{
		do {
			top++;
		} while (arr[top] < piv);
		do {
			under--;
		} while (arr[under] > piv);

		if (top < under)
		{
			swapInt(arr + top, arr + under);
			print_array(arr, sze);
		}
	}

	return (top);
}

/**
 * hoareSorting - Will implement the quicksort algorithm through recursion.
 * @arr: The array of integers to be sorted.
 * @sze: The size of the array.
 * @low: Starting index of the array partition to be ordered.
 * @high: Ending index of the array partition to be ordered.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoareSorting(int *arr, size_t sze, int low, int high)
{
	int split;

	if (high - low > 0)
	{
		split = hoare_partScheme(arr, sze, low, high);
		hoareSorting(arr, sze, low, split - 1);
		hoareSorting(arr, sze, split, high);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoareSorting(array, size, 0, size - 1);
}
