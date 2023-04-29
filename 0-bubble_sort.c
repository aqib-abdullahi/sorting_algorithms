#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array using bubble sort algorithm
 * @array: array to sort
 * @size: size of array to sort
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	int i = 0;
	int a = 0;
	int j = 0;
	int f = 1;

	if (!array || size < 2)
		return;
	j = size - 1;
	while (i < j)
	{
		if (array[i] > array[i + 1])
		{
			a = array[i];
			array[i] = array[i + 1];
			array[i + 1] = a;
			f = 1;
			print_array(array, size);
		}
		
		if (i == j - 1 && f == 1)
		{
			i = -1;
			f = 0;
			--j;
		}

		i++;
	}
}
