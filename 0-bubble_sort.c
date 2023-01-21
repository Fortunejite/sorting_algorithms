#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	size_t i, j = size, k;
	int tmp;

	for (i = 0; i < size; i++)
	{
		for(k = 0; k < j; k++)
		{
			if (k == size - 1)
				continue;
			if (array[k] > array[k + 1])
			{
				tmp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = tmp;
				print_array(array, size);
			}
		}
		j--;
	}
}
