#include "sort.h"

void swapInt(int *x, int *y);
void binHeap(int *arr, size_t sze, size_t bed, size_t source);
void heap_sort(int *array, size_t size);

/**
 * swapInt - Swaps two integers in an array.
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
 * binHeap - Function turns a binary tree into a full binary heap.
 * @arr: An array of integers representing a binary tree.
 * @sze: size of the array/binary tree.
 * @bed: index of the base row of the binary tree.
 * @source: root node of the binary tree.
 */

void binHeap(int *arr, size_t sze, size_t bed, size_t source)
{
	size_t left, right, big;

	left = 2 * source + 1;
	right = 2 * source + 2;
	big = source;

	if (left < bed && arr[left] > arr[big])
		big = left;
	if (right < bed && arr[right] > arr[big])
		big = right;

	if (big != source)
	{
		swapInt(arr + source, arr + big);
		print_array(arr, sze);
		binHeap(arr, sze, bed, big);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Will implement the sift-down heap sort algorithm
 *              Prints the array after each swap.
 */

void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || size < 2)
		return;

	for (x = (size / 2) - 1; x >= 0; x--)
		binHeap(array, size, size, x);

	for (x = size - 1; x > 0; x--)
	{
		swapInt(array, array + x);
		print_array(array, size);
		binHeap(array, size, x, 0);
	}
}
