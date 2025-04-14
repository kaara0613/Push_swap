#include <list.h>
#include <stdlib.h>

void    list_int_rev_rotate(t_list **list)
{
    int     idx;
    int     tmp;
    t_list  *head;

    idx = 0;
    head = *list;
    while (head->next != NULL)
    {
        head = head->next;
        idx++;
    }
    tmp = list_int_pop_at(list, idx);
    list_int_insert_at(list, tmp, 0);
}
