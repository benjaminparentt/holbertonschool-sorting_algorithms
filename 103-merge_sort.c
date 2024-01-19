#include "sort.h"

/**
 * print_parse - prints the value in array
 *
 * @array: array to be printed
 * @text: text to  printed alongside values
 * @low: lower bound
 * @high: upper bound
 */
void print_parse(int *array, const char *text, size_t low, size_t high)
{
	size_t i;
	char *separator = "";

	printf("[%s]: ", text);
	for (i = low; i <= high; i++)
	{
		printf("%s%d", separator, array[i]);
		separator = ", ";
	}
	printf("\n");
}
/**
 * join_parse - joins and sorts the values in the array
 * parsed
 *
 * @arr: array to be sorted
 * @low: starting index of the array passed
 * @high: ending index of the array passed
 * @mid: midpoint of the split array
 * @copy: array to store sorted values
 */
void join_parse(int *arr, size_t low, size_t high, size_t mid, int *copy)
{
	size_t hStart = mid + 1, newIndex, lStart = low, i;

	printf("Merging...\n");
	print_parse(arr, "left", low, mid);
	print_parse(arr, "right", mid + 1, high);

	for (newIndex = low; newIndex <= high; newIndex++)  /* fill sorted val */
	{
		if ((lStart <= mid && arr[lStart] <= arr[hStart]) || hStart > high)
			copy[newIndex] = arr[lStart++];
		else
			copy[newIndex] = arr[hStart++];
	}

	for (i = low; i <= high; i++)   /* update initial array with sorted arr */
		arr[i] = copy[i];

	print_parse(arr, "Done", low, high);
}

/**
 * parser - recursively perform merge sort and sort the
 * given array
 *
 * @array: array to be sorted
 * @lb: lower bound
 * @ub: upper bound
 * @copy: array to store sorted values
 */
void parser(int *array, size_t lb, size_t ub, int *copy)
{
	size_t mid;

	if (lb < ub)
	{
		mid = (ub + lb - 1) / 2;

		parser(array, lb, mid, copy);
		parser(array, mid + 1, ub, copy);

		join_parse(array, lb, ub, mid, copy);
	}
}

/**
 * merge_sort - application of the merge sort
 * algorithm to sort an array of integers
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *clone;

	if (!array || size < 2)   /* only one value or less in array */
		return;

	clone = malloc(sizeof(int) * size);
	if (!clone)
		return;

	parser(array, 0, size - 1, clone);
	free(clone);
}

