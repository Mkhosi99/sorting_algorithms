#include "sort.h"

/**
 * swapInt - Function swaps two integers in an array.
 * @x: first integer to swap.
 * @y: second integer to swap.
 */

void swapInt(int *x, int *y)
{
	int tempo;

	tempo = *x;
	*x = *y;
	*y = tempo;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Time Complexity: O(n^2)
 *
 * Description: Output the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *mini;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		mini = array + a;
		for (b = a + 1; b < size; b++)
			mini = (array[b] < *mini) ? (array + b) : mini;

		if ((array + a) != mini)
		{
			swapInt(array + a, mini);
			print_array(array, size);
		}
	}
}
