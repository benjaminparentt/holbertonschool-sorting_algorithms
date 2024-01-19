#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * print_sequence - prints an array
 * @array: given arrat
 * @low: lower boundary
 * @high: upper boundary
 */
void print_sequence(int *array, int low, int high)
{
	char *sep;

	for (sep = ""; low <= high; low++)
	{
		printf("%s%d", sep, array[low]);
		sep = ", ";
	}
	printf("\n");
}

/**
 * swap_dir - swaps tow elements if they are in the
 * specified bitonic direction
 * @array: given array
 * @e1: first element
 * @e2: second element
 * @dir: direction 1 for UP and 0 for DOWN
 */
void swap_dir(int *array, int e1, int e2, int dir)
{
	int temp;

	if (dir == (array[e1] > array[e2]))
	{
		temp = array[e1];
		array[e1] = array[e2];
		array[e2] = temp;
	}
}

/**
 * merge_sequence - merge sequence bitonically
 * @array: given array
 * @low: lower boundary
 * @high: high boundary
 * @dir: direction 1 for UP and 0 for DOWN
 * @size: array size
 */
void merge_sequence(int *array, size_t low, size_t high, int dir, size_t size)
{
	size_t middle, i, j;

	if (high - low < 1)
		return;

	middle = (low + high) / 2;
	for (i = low, j = middle + 1; i <= middle; i++, j++)
		swap_dir(array, i, j, dir);

	merge_sequence(array, low, middle, dir, size);
	merge_sequence(array, middle + 1, high, dir, size);
}

/**
 * make_sequence - make bitonic sequence
 * @array: given array
 * @low: lower boundary
 * @high: high boundary
 * @dir: direction 1 for UP and 0 for DOWN
 * @size: array size
 */
void make_sequence(int *array, size_t low, size_t high, int dir, size_t size)
{
	char *direction;
	size_t middle;

	if (high - low < 1)
		return;

	direction = dir ? "UP" : "DOWN";
	printf("Merging [%ld/%ld] (%s):\n", high - low + 1, size, direction);
	print_sequence(array, low, high);

	middle = (low + high) / 2;
	make_sequence(array, low, middle, 1, size);
	make_sequence(array, middle + 1, high, 0, size);

	merge_sequence(array, low, high, dir, size);
	printf("Result [%ld/%ld] (%s):\n", high - low + 1, size, direction);
	print_sequence(array, low, high);
}

/**
 * bitonic_sort -  sorts an array of integers in
 * ascending order using the Bitonic sort algorithm
 * @array: given array
 * @size: array size
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	make_sequence(array, 0, size - 1, 1, size);
}
