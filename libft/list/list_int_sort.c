#include "list.h"
#include "stdlib.h"
#include <stdbool.h>

void    swap(t_list **list, int n);

t_list  *list_int_sort(t_list *list)
{
    t_list *result;

    result = list_int_clone(list);
    swap(&result, list_int_count(list));
    return (result);
}

// void    swap(t_list *list, int n)
// {
//     int     idx1;
//     int		idx2;
//     bool    swaped;
    
//     idx1 = 0;
//     while (idx1 < n - 1)
//     {
//         idx2 = 0;
//         swaped = false;
//         while (idx2 < n - 1 - idx1)
//         {
//             if (list_int_access_at(list,idx2) > list_int_access_at(list,idx2 + 1))
//             {
//                 list_int_insert_at(&list, list_int_pop_at(&list, idx2), idx2 + 1);
//                 swaped = true;
//             }
//             idx2++;
//         }
//         if (!swaped)
//             break ;
//         idx1++;
//     }
// }

// void swap(t_list *list, int n)
// {
//     int  idx1;
//     int  idx2;
//     bool swapped;

//     idx1 = 0;
//     while (idx1 < n - 1)
//     {
//         idx2 = 0;
//         swapped = false;
//         while (idx2 < n - 1 - idx1)
//         {
//             if (list_int_access_at(list, idx2) > list_int_access_at(list, idx2 + 1))
//             {
//                 list_int_insert_at(&list, list_int_pop_at(&list, idx2), idx2);
//                 swapped = true;
//             }
//             idx2++;
//         }
//         if (!swapped)
//             break;
//         idx1++;
//     }
// }

void swap(t_list **list, int n)
{
    int  idx1;
    int  idx2;
    bool swapped;

    // listがNULL・要素数不十分なら何もしない
    if (!list || !*list || n < 2)
        return;

    idx1 = 0;
    while (idx1 < n - 1)
    {
        idx2 = 0;
        swapped = false;
        while (idx2 < n - 1 - idx1)
        {
            // 比較の際は「*list, idx2」でアクセス
            if (list_int_access_at(*list, idx2) > list_int_access_at(*list, idx2 + 1))
            {
                // idx2 の要素を pop して、idx2+1 に挿入（swap のイメージ）
                int tmp = list_int_pop_at(list, idx2);
                list_int_insert_at(list, tmp, idx2 + 1);
                swapped = true;
            }
            idx2++;
        }
        if (!swapped)
            break;  // 1回も入れ替えがなければソート済み
        idx1++;
    }
}


