#include "list.h"
#include "list.h"
#include <stdlib.h>

int list_int_pop(t_list **list)
{
	t_list  *head;
	int     result;
	
	head = *list;
	*list = head->next;
	result = head->element.i;
	head->next = NULL;
	free(head);
	return (result);
}
