#include "sort.h"

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
 * bubble_sort - Function sorts array of integers in ascending order
 * @array: The array of integers to be sorted.
 * @size: Indicates the size of the array.
 * Time Complexity: O(n^2)
 * Description: Outputs the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, lenth = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (x = 0; x < lenth - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swapInt(array + x, array + x + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		lenth--;
	}
}
