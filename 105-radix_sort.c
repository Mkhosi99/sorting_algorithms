#include "sort.h"
#include <stdlib.h>

/**
 * power10 - Function calculates a positive power of 10
 * @pow: The power of 10 to calculate
 *
 * Return: The corresponding power of 10 should be returned
 */

unsigned int power10(unsigned int pow)
{
	unsigned int x, answer;

	answer = 1;
	for (x = 0; x < pow; x++)
		answer *= 10;
	return (answer);
}

/**
 * cSort - Will sort an array of integers in ascending order at a specific
 *         digit location using the Counting sort algorithm
 * @arr: the array to sort
 * @sze: the size of the array to sort
 * @dig: the digit to sort by
 *
 * Return: 1 if there is a need to keep sorting, or 0 if not
 */


unsigned int cSort(int *arr, size_t sze, unsigned int dig)
{
	int x, counter[10] = {0};
	int *dup = NULL;
	size_t y, tempo, whole = 0;
	unsigned int dup1, dup2, order = 0;

	dup2 = power10(dig - 1);
	dup1 = dup2 * 10;
	dup = malloc(sizeof(int) * sze);
	if (dup == NULL)
		exit(1);
	for (y = 0; y < sze; y++)
	{
		dup[y] = arr[y];
		if (arr[y] / dup1 != 0)
			order = 1;
	}
	for (x = 0; x < 10 ; x++)
		counter[x] = 0;
	for (y = 0; y < sze; y++)
		counter[(arr[y] % dup1) / dup2] += 1;
	for (x = 0; x < 10; x++)
	{
		tempo = counter[x];
		counter[x] = whole;
		whole += tempo;
	}
	for (y = 0; y < sze; y++)
	{
		arr[counter[(dup[y] % dup1) / dup2]] = dup[y];
		counter[(dup[y] % dup1) / dup2] += 1;
	}
	free(dup);
	return (order);
}

/**
 * radix_sort - sorts an array of integers in ascending order using
 *              the Radix sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	unsigned int x, order = 1;

	if (array == NULL || size < 2)
		return;
	for (x = 1; order == 1; x++)
	{
		order = cSort(array, size, x);
		print_array(array, size);
	}
}
