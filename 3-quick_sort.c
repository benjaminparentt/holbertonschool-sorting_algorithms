#include "sort.h"

/**
 * swap - Swap values of start and next index.
 * @array: the array to work in.
 * @size: size of array.
 * @low: left most value
 * @high: right most value
 * Return: nothing.
 */
void swap(int *array, size_t size, int low, int high)
{
	int temp;

	if (array[low] != array[high])
	{
		temp = array[low];
		array[low] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
}
/**
 * partition - using Lomuto partition scheme for quicksort
 * @array: pointer to array
 * @size: size of array
 * @low: left most value
 * @high: right most value
 * Return: pivot value
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot_value = array[high];

	int i = low - 1, j;

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot_value)
		{
			i++;
			swap(array, size, i, j);

		}
	}
	swap(array, size, i + 1, high);

	return (i + 1);
}
/**
 * quicksort_recursion - recursive funtion for quicksort
 * @array: pointer to array
 * @size: size of array
 * @low: lowest value
 * @high: highest value
 */
void quicksort_recursion(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, size, low, high);
		quicksort_recursion(array, size, low, pivot_index - 1);
		quicksort_recursion(array, size, pivot_index + 1, high);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to sort.
 * @size: size of the array.
 * Return: nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_recursion(array, size, 0, size - 1);
}
