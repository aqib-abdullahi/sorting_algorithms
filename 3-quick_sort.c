#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort - sorst using the quick sort algorithm
 * @array: array to be sorted.
 * @size: size of array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - ...
 * @array: array to be sorted
 * @size: size of array
 * @lower: lower arr
 * @higher: higher arr
 * Return: Nothing
 */

void quick_sort_rec(int *array, int lower, int higher, size_t size)
{
	int l_p = 0;

	if (lower < higher)
	{
		l_p = lomuto_partition(array, lower, higher, size);
		quick_sort_rec(array, lower, l_p - 1, size);
		quick_sort_rec(array, l_p + 1, higher, size);
	}
}

/**
 * lomuto_partion - ...
 * @array: array to be considered
 * @size: size of array
 * @higher: higher element
 * @lower: lower element
 * Return: Nothing
 */


int lomuto_partition(int *array, int lower, int higher, size_t size)
{
	int i = 0, j = 0, pivot = 0, a = 0;

	pivot = array[higher];
	i = lower;

	for (j = lower; j < higher; ++j)
	{
		if (array[j] < pivot)
		{
			a = array[i];
			array[i] = array[j];
			array[j] = a;

			if (a != array[i])
				print_array(array, size);

			++i;
		}
	}

	a = array[i];
	array[i] = array[higher];
	array[higher] = a;

	if (a != array[i])
		print_array(array, size);

	return (i);
}
