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
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Use of the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{
	size_t distnce, a, b;

	if (array == NULL || size < 2)
		return;

	for (distnce = 1; distnce < (size / 3);)
		distnce = distnce * 3 + 1;

	for (; distnce >= 1; distnce /= 3)
	{
		for (a = distnce; a < size; a++)
		{
			b = a;
			while (b >= distnce && array[b - distnce] > array[b])
			{
				swapInt(array + b, array + (b - distnce));
				b -= distnce;
			}
		}
		print_array(array, size);
	}
}
