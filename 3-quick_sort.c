#include "sort.h"

void swapInt(int *x, int *y);
int lomuto_partScheme(int *arr, size_t sze, int low, int high);
void lomutoSorting(int *arr, size_t sze, int low, int high);
void quick_sort(int *array, size_t size);

/**
 * swapInt - Fuction swaps two integers in an array.
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
 * lomuto_partScheme - Order a subset of an array of integers using the
 *                     lomuto partition scheme (the last element as pivot).
 * @arr: Integer array
 * @sze: The size of array.
 * @low: starting index of the subset to order.
 * @high: ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int lomuto_partScheme(int *arr, size_t sze, int low, int high)
{
	int *piv, up, down;

	piv = arr + high;
	for (up = down = low; down < high; down++)
	{
		if (arr[down] < *piv)
		{
			if (up < down)
			{
				swapInt(arr + down, arr + up);
				print_array(arr, sze);
			}
			up++;
		}
	}

	if (arr[up] > *piv)
	{
		swapInt(arr + up, piv);
		print_array(arr, sze);
	}

	return (up);
}

/**
 * lomutoSorting - Implements the quicksort algorithm via recursion.
 * @arr: Integer array to sort
 * @sze: The size of array.
 * @low: Starting index of array partition to order.
 * @high: Ending index of array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void lomutoSorting(int *arr, size_t sze, int low, int high)
{
	int split;

	if (high - low > 0)
	{
		split = lomuto_partScheme(arr, sze, low, high);
		lomutoSorting(arr, sze, low, split - 1);
		lomutoSorting(arr, sze, split + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Outputs
 *              the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomutoSorting(array, size, 0, size - 1);
}
