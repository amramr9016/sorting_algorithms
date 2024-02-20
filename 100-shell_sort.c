#include "sort.h"

/**
 * exchange_integers - Swap two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */
void exchange_integers(int *first, int *second)
{
	int temporary;

	temporary = *first;
	*first = *second;
	*second = temporary;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @arr: An array of integers.
 * @arr_size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *arr, size_t arr_size)
{
	size_t gap, i, j;

	if (arr == NULL || arr_size < 2)
		return;

	for (gap = 1; gap < (arr_size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < arr_size; i++)
		{
			j = i;
			while (j >= gap && arr[j - gap] > arr[j])
			{
				exchange_integers(arr + j, arr + (j - gap));
				j -= gap;
			}
		}
		print_array(arr, arr_size);
	}
}
