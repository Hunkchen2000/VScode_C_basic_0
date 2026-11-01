#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 50

typedef struct {
    char city[MAX_LEN];        // 城市
    char district[MAX_LEN];    // 區域
    char street[MAX_LEN];      // 街道
} Address;

// 外部結構體：學生（包含嵌套的Address）
typedef struct {
    char name[MAX_LEN];        // 學生名字
    int student_id;            // 學號
    Address address;           // 嵌套的地址結構體
} Student;

typedef Student *StudentPtr;

int main(void)
{
    /*使用指針和動態內存*/
    StudentPtr hunkchen = (StudentPtr)malloc(sizeof(Student));
    if(hunkchen == NULL)
    { 
        printf("內存分配失敗\n");
        return 1;
    }
    
    // ? 正確的嵌套結構體初始化
    *hunkchen = (Student){
                           "CCCCCCC",              // name
                            862103,                 // student_id
                            {                       // address 嵌套結構體
                            "AAAAA",            // city
                            "BBBBB",            // district
                            "ADDRESS"           // street
                             }
    };
    
    // 打印驗證
    printf("學生名字：%s\n", hunkchen->name);
    printf("學號：%d\n", hunkchen->student_id);
    printf("城市：%s\n", hunkchen->address.city);
    printf("區域：%s\n", hunkchen->address.district);
    printf("街道：%s\n", hunkchen->address.street);
    
    // 釋放內存
    free(hunkchen);
    hunkchen = NULL;
    
    return 0;
}