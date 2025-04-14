#include "list.h"
#include <stdlib.h>

int list_int_count(t_list *list)
{
	int result;
	t_list *head;

    result = 0;
    head = list;
    while (head->next != NULL)
    {
        result++;
        head = head->next;
    }
    return (result + 1);
}
