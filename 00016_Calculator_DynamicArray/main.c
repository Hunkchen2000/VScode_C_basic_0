#include <stdio.h>
#include <stdlib.h>
#define ROW 5
#define COL 4

int main() {

    int n = 5; // 元素個數
    int *arr1 = (int *)malloc(n * sizeof(int)); // 動態配置
    int *matrix = (int *)malloc(ROW * COL * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr1[i] = i + 1; // 初始化元素
    }
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            matrix[i * COL + j] = i * COL + j + 1; // 初始化矩陣元素
        }
    }

    // 取得元素個數：直接使用變數 n
    printf("陣列元素個數：%d\n", n);
    
    // 取得總位元組大小 (Bytes)
    printf("總記憶體大小：%zu bytes\n", n * sizeof(int));
    size_t total_size = ROW * COL * sizeof(int);
    printf("陣列維度: %d x %d\n", ROW, COL);
    printf("矩陣總記憶體大小：%zu bytes\n", total_size);

  for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]); // 輸出元素
    }

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", matrix[i * COL + j]); // 輸出矩陣元素
        }
        printf("\n");
    }


    free(arr1);
    free(matrix);
    return 0;
}
