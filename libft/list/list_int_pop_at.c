#include "list.h"
#include <stdlib.h>

int list_int_pop_at(t_list **list, int n)
{
    int idx;
    int result;
    t_list  *head;
    t_list  *previous_head;

    idx = 0;
    head = *list;
    if (n == 0)
    	return (list_int_pop(list));
    while (head->next != NULL && idx < n - 1)
    {
        head = head->next;
        idx++;
    }
    previous_head = head;
    head = head->next;
    result = head->element.i;
    previous_head->next = head->next;
    free(head);
    return (result);
}
