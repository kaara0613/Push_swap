#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bsearch用の比較関数
int compare_ints(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int* coordinate_compression(int *arr, int elements_nbr)
{
    // 結果を格納するための動的メモリを確保
    int *compressed = (int *)malloc(sizeof(int) * elements_nbr);
    if (compressed == NULL) {
        return NULL; // メモリ確保失敗時など
    }

    // 元の配列をコピーしてソート
    int *temp = (int *)malloc(sizeof(int) * elements_nbr);
    if (temp == NULL) {
        free(compressed);
        return NULL;
    }
    memcpy(temp, arr, sizeof(int) * elements_nbr);
    qsort(temp, elements_nbr, sizeof(int), compare_ints);

    // ソートされた配列から重複を除去し、unique_count個を使う
    int unique_count = 1;
    for (int i = 1; i < elements_nbr; i++) {
        if (temp[i] != temp[unique_count - 1]) {
            temp[unique_count] = temp[i];
            unique_count++;
        }
    }

    // 元の配列の各要素の圧縮後インデックスを調べる (バイナリサーチ)
    for (int i = 1; i < elements_nbr; i++) {
        int *p = (int *)bsearch(&arr[i], temp, unique_count, sizeof(int), compare_ints);
        // 見つかった要素の先頭からのオフセットがそのまま圧縮後の値となる
        compressed[i] = (int)(p - temp);
    }

    free(temp);
    return compressed;
}

// 動作確認用サンプル(main関数)
// int main(void) {
//     int arr[] = {-1848002553 -1111746549 -721467381 -541743068 1656934436 -639625173 -320286675 2039302195};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int *compressed = coordinate_compression(arr, n);
//     if (compressed == NULL) {
//         fprintf(stderr, "Memory allocation failed.\n");
//         return 1;
//     }

//     // 結果の表示
//     for (int i = 0; i < n; i++) {
//         printf("%d -> %d\n", arr[i], compressed[i]);
//     }

//     free(compressed);
//     return 0;
// }
