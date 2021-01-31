#include "sort.h"

/**
 * insertion_sort_list - sorts a list with the insertion method
 *
 * @list: list to sort
 *
 * Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *aux = NULL, *ref = NULL;

	if (!*list)
		return;

	current = *list;
	current = current->next;

	while (current)
	{
		aux = current;
		ref = current->next;
		while ((aux->prev) && (current->n < aux->prev->n))
			aux = aux->prev;
		if (aux != current)
		{
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;

			if (aux->prev)
				aux->prev->next = current;
			else
				(*list) = current;

			current->prev = aux->prev;
			aux->prev = current;
			current->next = aux;
			print_list(*list);
		}
		current = ref;
	}
}
