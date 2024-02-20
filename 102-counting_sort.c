#include "sort.h"

/**
 * find_maximum - Find the maximum value in an array of integers.
 * @arr: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int find_maximum(int *arr, int size)
{
	int maximum, i;

	for (maximum = arr[0], i = 1; i < size; i++)
	{
		if (arr[i] > maximum)
			maximum = arr[i];
	}

	return (maximum);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @arr: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *arr, size_t size)
{
	int *count, *sorted, maximum, i;

	if (arr == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maximum = find_maximum(arr, size);
	count = malloc(sizeof(int) * (maximum + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (maximum + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[arr[i]] += 1;
	for (i = 1; i < (maximum + 1); i++)
		count[i] += count[i - 1];
	print_array(count, maximum + 1);

	for (i = (int)size - 1; i >= 0; i--)
	{
		sorted[count[arr[i]] - 1] = arr[i];
		count[arr[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		arr[i] = sorted[i];

	free(sorted);
	free(count);
}
