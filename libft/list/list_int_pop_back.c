#include <list.h>
#include <stdlib.h>

int list_int_pop_back(t_list **list)
{
    int result;
    t_list  *head;

    head = *list;
    while (head->next == NULL)
        head = head->next;
    result = list_int_pop(&head);
    return (result);
}
