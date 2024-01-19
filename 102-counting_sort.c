#include "sort.h"

/**
 * fetch_maxi - function gets the maximum value in an array of integers.
 * @arr: An array of integers.
 * @sze: The size of the array.
 *
 * Return: maximum integer in the array is returned.
 */

int fetch_maxi(int *arr, int sze)
{
	int maxi, x;

	for (maxi = arr[0], x = 1; x < sze; x++)
	{
		if (arr[x] > maxi)
			maxi = arr[x];
	}

	return (maxi);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *sort, maxi, x;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	maxi = fetch_maxi(array, size);
	counter = malloc(sizeof(int) * (maxi + 1));
	if (counter == NULL)
	{
		free(sort);
		return;
	}

	for (x = 0; x < (maxi + 1); x++)
		counter[x] = 0;
	for (x = 0; x < (int)size; x++)
		counter[array[x]] += 1;
	for (x = 0; x < (maxi + 1); x++)
		counter[x] += counter[x - 1];
	print_array(counter, maxi + 1);

	for (x = 0; x < (int)size; x++)
	{
		sort[counter[array[x]] - 1] = array[x];
		counter[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
		array[x] = sort[x];

	free(sort);
	free(counter);
}
