#include "sort.h"

/**
 * switch_nodes - switches two nodes
 *
 * @first: first node
 * @second: second node
 *
 * Return: void
*/
void switch_nodes(listint_t *first, listint_t *second)
{
	if (second->prev)
		second->prev->next = first;
	if (first->next)
		first->next->prev = second;
	first->prev = second->prev;
	second->next = first->next;
	first->next = second;
	second->prev = first;
}

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

	if (!*list || !list)
		return;

	current = (*list)->next;

	while (current)
	{
		aux = current->prev;
		ref = current->next;
		while (aux && current->n < aux->n)
		{
			switch_nodes(current, aux);
			aux = current;
			aux = aux->prev;
			if ((*list)->prev)
				(*list) = (*list)->prev;
			print_list(*list);
		}
		current = ref;
	}
}
