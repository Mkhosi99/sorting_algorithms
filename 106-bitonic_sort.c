#include "sort.h"

void swapInt(int *x, int *y);
void bitMerge(int *arr, size_t sze, size_t begin, size_t seqnce, char direc);
void bitSeq(int *arr, size_t sze, size_t begin, size_t seqnce, char direc);
void bitSort(int *arr, size_t sze);

/**
 * swapInt - Function swaps two integers in an array.
 * @x: Indicates the first integer to swap.
 * @y: Indicates the second integer to swap.
 */
void swapInt(int *x, int *y)
{
	int tempo;

	tempo = *x;
	*x = *y;
	*y = tempo;
}

/**
 * bitMerge - Function sorts a bitonic sequence inside an array of integers.
 * @arr: The array of integers.
 * @sze: The size of the array.
 * @begin: Starting index of the sequence in array to be sorted.
 * @seqnce: The size of the sequence to be sorted.
 * @direc: The direction to sort array in.
 */
void bitMerge(int *arr, size_t sze, size_t begin, size_t seqnce, char direc)
{
	size_t x, hop = seqnce / 2;

	if (seqnce > 1)
	{
		for (x = begin; x < begin + hop; x++)
		{
			if ((direc == ASC && arr[x] > arr[x + hop]) ||
			    (direc == DESC && arr[x] < arr[x + hop]))
				swapInt(arr + x, arr + x + hop);
		}
		bitMerge(arr, sze, begin, hop, direc);
		bitMerge(arr, sze, begin + hop, hop, direc);
	}
}

/**
 * bitSeq - Will convert an array of integers into a bitonic sequence.
 * @arr: The array of integers.
 * @sze: The size of the array.
 * @begin: Starting index of a block of the building bitonic sequence.
 * @seqnce: The size of a block of the building bitonic sequence.
 * @direc: The direction to sort the bitonic sequence block in.
 */
void bitSeq(int *arr, size_t sze, size_t begin, size_t seqnce, char direc)
{
	size_t chop = seqnce / 2;
	char *string = (direc == ASC) ? "UP" : "DOWN";

	if (seqnce > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seqnce, sze, string);
		print_array(arr + begin, seqnce);

		bitSeq(arr, sze, begin, chop, ASC);
		bitSeq(arr, sze, begin + chop, chop, DESC);
		bitMerge(arr, sze, begin, seqnce, direc);

		printf("Result [%lu/%lu] (%s):\n", seqnce, sze, string);
		print_array(arr + begin, seqnce);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitSeq(array, size, 0, size, ASC);
}
