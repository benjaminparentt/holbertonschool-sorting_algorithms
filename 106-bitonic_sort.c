#include "sort.h"
void compare_swap_down(int *array_init, int *array, size_t size_init, size_t size, int *flag)
{
	int n;
	size_t i;
	(void)array_init;

	//printf("compare_down\n");
	if (flag[0] == 0)
	{
		for (i = 0; i < size/2 ; i++)
		{
			if (array[0] < array[size - 1])
			{
				n = array[0];
				array[0] = array[size - 1];
				array[size - 1] = n;
				printf("Result [%lu/%lu] (DOWN):\n", size, size_init);
				print_array(array, size);
			}
		}
	}
}
void compare_swap_up(int *array_init, int *array, size_t size_init, size_t size, int *flag)
{
	int n;
	size_t i;
	(void)array_init;

	//printf("size up:%lu\n", size);
	//printf("array[0] up:%d\n", array[0]);
	//printf("array[size-1] up:%d\n", array[size-1]);
	//printf("compare_up\n");
	if (flag[0] == 0)
	{
		for (i = 0; i < size/2 ; i++)
		{
			if (array[0] > array[size - 1])
			{
				n = array[0];
				array[0] = array[size - 1];
				array[size - 1] = n;
				printf("Result [%lu/%lu] (UP):\n", size, size_init);
				print_array(array, size);
			}
		}
	}
}
void bitonic_deep_down(int *array_init, int *array, size_t size_init, size_t size, int *flag)
{
	(void)array;

	//printf("deep_down_pre, size:%lu\n", size);
	if (size < 2)
	{
		flag[0] = 0;
		return;
	}
	//printf("deep_down:i=%lu\n", i);
	printf("Merging [%lu/%lu] (DOWN):\n", size, size_init);
	print_array(array, size);
	bitonic_deep_up(array_init, array, size_init, size / 2, flag);
	compare_swap_up(array_init, array, size_init, size, flag);
	//flag[0] = 0;
	bitonic_deep_down(array_init, array + (size/2), size_init, size / 2, flag);
	//flag[0] = 1;
	compare_swap_down(array_init, array, size_init, size, flag);
	//compare_swap(array, 0, i);
	//printf("despues de swap\n");
	//print_array(array, size);
}
void bitonic_deep_up(int *array_init, int *array, size_t size_init, size_t size, int *flag)
{
	(void)array;

	//printf("deep_up_pre, size:%lu\n", size);
	if (size < 2)
	{
		flag[0] = 0;
		return;
	}
	//printf("deep_up:i=%lu\n", i);
	printf("Merging [%lu/%lu] (UP):\n", size, size_init);
	print_array(array, size);
	bitonic_deep_up(array_init, array, size_init, size / 2, flag);
	compare_swap_up(array_init, array, size_init, size, flag);
	bitonic_deep_down(array_init, array + (size/2), size_init, size / 2, flag);
	compare_swap_down(array_init, array, size_init, size, flag);
	//flag[0] = 1;
	//compare_swap(array, 0, i);
	//printf("despues de swap\n");
	//print_array(array, size);
}
/**
 *
 *
 *
 *
 **/
void bitonic_sort(int *array, size_t size)
{
	size_t size_init = size;
	int *array_init = array;
	int *flag;
	int aux = {0};

	flag = &aux;
	if (array)
	{
		bitonic_deep_up(array_init, array, size_init, size, flag);
	}	
}
