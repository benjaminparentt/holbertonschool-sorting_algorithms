#include "sort.h"

/**
 * arr_zero_init - initialize array by 0
 *
 * @array: array to be initialized
 * @size: size of the array
 */
void arr_zero_init(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}

/**
 * get_max - gets the maximum value in the array
 *
 * @array: array to get max value from
 * @size: size of the array
 *
 * Return: maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	if (size < 2)
		return (0);

	max = array[0];	/* start from first index */

	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - sorts an array using the counting
 * sort algorithm
 *
 * @array: initial array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int k = get_max(array, size), j, *position, *sumPosition, *sorted;
	size_t i;

	if (k == 0)
		return;

	position = malloc(sizeof(int) * (k + 1));
	if (!position)
		return;
	arr_zero_init(position, k + 1);

	for (i = 0; i < size; i++)
		position[array[i]] += 1;    /* set one to the positions */

	sumPosition = malloc(sizeof(int) * (k + 1));
	if (!sumPosition)
		return;
	arr_zero_init(sumPosition, k + 1);
	sumPosition[0] = position[0];   /* make first index equal */

	for (j = 1; j < (k + 1); j++)
		sumPosition[j] = position[j] + sumPosition[j - 1];

	free(position), print_array(sumPosition, k + 1);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	arr_zero_init(sorted, size);

	for (i = 0; i < size; i++)  /* get the sorted array */
	{
		sumPosition[array[i]] -= 1;
		sorted[sumPosition[array[i]]] = array[i];
	}
	free(sumPosition);

	for (i = 0; i < size; i++)  /* update array */
		array[i] = sorted[i];
	free(sorted);
}

