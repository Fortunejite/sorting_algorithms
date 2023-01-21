#include "sort.h"

listint_t *swap_node_insert(listint_t *tmp)
{
	listint_t *pre;

	pre = tmp->next;
	tmp->next = pre->next;
	pre->prev = tmp->prev;
	pre->next = tmp;
	tmp->prev = pre;
	return (pre);

}

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp_l;
	listint_t *lis = *list;

	while (list != NULL)
	{
		if (list == NULL)
			continue;
		if (lis->n > lis->next->n)
		{
			tmp_l = swap_node_insert(lis);
			print_list(lis);
			while (tmp_l != NULL)
			{
				if (tmp_l->n < tmp_l->prev->n)
				{
					swap_node_insert(tmp_l);
					print_list(lis);
					tmp_l = tmp_l->prev;
				}
			}
		}
		lis = lis->next;
	}
}
