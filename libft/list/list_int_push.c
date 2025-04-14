#include "list.h"
#include <stdlib.h>

t_list  *allocation_list();

void    list_int_push(t_list **list, int n)
{
	t_list  *head;

	head = *list;
	if (*list == NULL)
	{
		*list = allocation_list();
		(*list)->element.i = n;
		return ;
	}
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = allocation_list();
		head->next->element.i = n;
	}
}

t_list  *allocation_list()
{
	t_list  *list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->next = NULL;
	return (list);
}
