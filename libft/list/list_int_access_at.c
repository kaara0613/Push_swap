#include "list.h"
#include <stdlib.h>

int	list_int_access_at(t_list *list, int i)
{
    int	idx;
    t_list *head;

    idx = 0;
    head = list;
    while (head->next != NULL && idx < i)
    {
        head = head->next;
        idx++;
    }
	return (head->element.i);
}

// int	list_int_access_at(t_list *list, int i)
// {
//     t_list *curr = list;
//     int     idx  = 0;

//     // リストが空 or インデックスが負ならエラー扱い
//     if (curr == NULL || i < 0)
//     {
//         // 必要に応じてエラー処理
//         // 例：return -1; とか、エラーコードなど
//         return 0;
//     }

//     // i番目になるまで進む
//     while (curr->next != NULL && idx < i)
//     {
//         curr = curr->next;
//         idx++;
//     }
//     // ループを抜けたときにi番目がcurrになる
//     // ただしリスト長 < i の場合、最後のノードを返す (現状の処理)

//     return curr->element.i;
// }
