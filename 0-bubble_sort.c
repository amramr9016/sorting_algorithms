#include "sort.h"

/**
 * swap_elements - Swap two elements in an array.
 * @x: The first element to swap.
 * @y: The second element to swap.
 */
void swap_elements(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order using bubble sort.
 * @arr: An array of integers to sort.
 * @arr_size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *arr, size_t arr_size)
{
	size_t idx, length = arr_size;
	bool swapped = false;

	if (arr == NULL || arr_size < 2)
		return;

	while (swapped == false)
	{
		swapped = true;
		for (idx = 0; idx < length - 1; idx++)
		{
			if (arr[idx] > arr[idx + 1])
			{
				swap_elements(arr + idx, arr + idx + 1);
				print_array(arr, arr_size);
				swapped = false;
			}
		}
		length--;
	}
}
