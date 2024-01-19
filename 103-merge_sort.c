#include "sort.h"

void mergeSubarray(int *subary, int *bufr, size_t start, size_t middl,
		size_t last);
void mergeSort_recurse(int *subary, int *bufr, size_t start, size_t last);
void merge_sort(int *array, size_t size);

/**
 * mergeSubarray - Sort a subarray of integers.
 * @subary: A subarray of an array of integers to be sorted.
 * @bufr: Buffer that will store the sorted subarray.
 * @start: The front index of the array.
 * @middl: The middle index of the array.
 * @last: The back index of the array.
 */

void mergeSubarray(int *subary, int *bufr, size_t start, size_t middl,
		size_t last)
{
	size_t x, y, z = 0;

	printf("Merging...\n[left]: ");
	print_array(subary + start, middl - start);

	printf("[right]: ");
	print_array(subary + middl, last - middl);

	for (x = start, y = middl; x < middl && y < last; z++)
		bufr[z] = (subary[x] < subary[y]) ? subary[x++] : subary[y++];
	for (; x < middl; x++)
		bufr[z++] = subary[x];
	for (; y < last; y++)
		bufr[z++] = subary[y];
	for (x = start, z = 0; x < last; x++)
		subary[x] = bufr[z++];

	printf("[Done]: ");
	print_array(subary + start, last - start);
}

/**
 * mergeSort_recurse - Implements the merge sort algorithm via recursion.
 * @subary: A subarray of an array of integers to be sorted.
 * @bufr: A buffer that will store the sorted result.
 * @start: The front index of the subarray.
 * @last: The back index of the subarray.
 */
void mergeSort_recurse(int *subary, int *bufr, size_t start, size_t last)
{
	size_t middl;

	if (last - start > 1)
	{
		middl = start + (last - start) / 2;
		mergeSort_recurse(subary, bufr, start, middl);
		mergeSort_recurse(subary, bufr, middl, last);
		mergeSubarray(subary, bufr, start, middl, last);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Will implement the top-down merge sort algorithm.
 */


void merge_sort(int *array, size_t size)
{
	int *bufr;

	if (array == NULL || size < 2)
		return;

	bufr = malloc(sizeof(int) * size);
	if (bufr == NULL)
		return;

	mergeSort_recurse(array, bufr, 0, size);

	free(bufr);
}
