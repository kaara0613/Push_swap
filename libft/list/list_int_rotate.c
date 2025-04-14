#include "list.h"

void    list_int_rotate(t_list **list)
{
    int tmp;

    tmp = list_int_pop(list);
    list_int_push(list, tmp);
}
