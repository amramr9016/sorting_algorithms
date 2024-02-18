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
 * @n: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *arr, size_t n)
{
	size_t i, len = n;
	bool is_sorted = false;

	if (arr == NULL || n < 2)
		return;

	while (!is_sorted)
	{
		is_sorted = true;
		for (i = 0; i < len - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap_elements(arr + i, arr + i + 1);
				print_array(arr, n);
				is_sorted = false;
			}
		}
		len--;
	}
}
