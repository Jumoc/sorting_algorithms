#include "sort.h"

/**
 * selection_sort - sorts an array with selection method
 *
 * @array: first node
 * @size: second node
 *
 * Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, idx;

	if (!array)
		return;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		idx = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				idx = j;
			}
		}
		if (idx > 0)
		{
			array[idx] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
