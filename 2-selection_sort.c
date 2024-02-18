#include "sort.h"

/**
 * exchange_values - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void exchange_values(int *a, int *b)
{
	int temporary;

	temporary = *a;
	*a = *b;
	*b = temporary;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @arr: An array of integers.
 * @arr_size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *arr, size_t arr_size)
{
	int *minimum;
	size_t i, j;

	if (arr == NULL || arr_size < 2)
		return;

	for (i = 0; i < arr_size - 1; i++)
	{
		minimum = arr + i;
		for (j = i + 1; j < arr_size; j++)
			minimum = (arr[j] < *minimum) ? (arr + j) : minimum;

		if ((arr + i) != minimum)
		{
			exchange_values(arr + i, minimum);
			print_array(arr, arr_size);
		}
	}
}

