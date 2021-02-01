#include "sort.h"

/**
 * swap - swaps two numbers
 *
 * @a: array to sort
 * @b: lowest index
 * @array: array
 * @size: size of the array
 *
 * Return: void
*/
void swap(int *a, int *b, int *array, size_t size)
{
	int t = *a;
	*a = *b;
	*b = t;
	if (*a != *b)
		print_array(array, size);
}

/**
 * partition - sets the pivot on the right position
 *
 * @array: array to sort
 * @low: lowest index
 * @high: highest index
 * @size: size of the array
 *
 * Return: void
*/
int partition(int *array, int low, int high, int size)
{
	int i, j;

	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < array[high])
		{
			i++;
			swap(&array[i], &array[j], array, size);
		}
	}
	swap(&array[i + 1], &array[high], array, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - sorts an array with the quicksort method
 *
 * @array: array to sort
 * @low: lowest index
 * @high: highest index
 * @size: size of the array
 *
 * Return: void
*/
void quick_sort_recursive(int *array, int low, int high, int size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		/*Left*/
		quick_sort_recursive(array, low, pi - 1, size);
		/*Right*/
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array with the quicksort method
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
*/
void quick_sort(int *array, size_t size)
{
	int high;

	if (!array)
		return;

	high = (int) (size - 1);
	quick_sort_recursive(array, 0, high, size);
}
