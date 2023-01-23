#include "sort.h"

/*
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *focus, *prev, *tmp;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	focus = (*list)->next;
	while (focus != NULL)
	{
		prev = focus->prev;
		tmp = focus->next;
		while (prev != NULL && focus->n < prev->n)
		{
			prev->next = focus->next;
			if (focus->next != NULL)
				focus->next->prev = prev;
			focus->next = prev->prev;
			focus->prev = prev;
			if (prev->prev != NULL)
				prev->prev->next = focus;
			else
				*list = focus;
			prev->prev = focus;
			prev = focus->prev;
			print_list((const listint_t *)*list);
		}
		focus = tmp;
	}
}
