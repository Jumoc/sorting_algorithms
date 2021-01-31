#include "sort.h"

/**
 * bubble_sort - sorts an array with the bubble sort method
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
    int aux = 0;
    size_t i, j = 0;

    for (i = 1; i < size; i++)
    {
        for (j = 0; j < (size - i); j++)
        {
            if (array[j] > array[j + 1])
            {
                aux = array[j + 1];
                array[j + 1] = array[j];
                array[j] = aux;
                print_array(array, size);
            }
        }
    }
}
