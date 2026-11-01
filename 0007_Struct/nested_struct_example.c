#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

// 定義地址結構體（嵌套的內部結構體）
typedef struct 
{
    char city[MAX_LEN];        // 城市
    char district[MAX_LEN];    // 區域
    char street[MAX_LEN];      // 街道
} Address;

// 定義學生結構體（包含嵌套的Address結構體）
typedef struct 
{
    char name[MAX_LEN];        // 學生名字
    int student_id;            // 學號
    Address address;           // 嵌套的地址結構體
} Student;

// 使用指針版本
typedef Student *StudentPtr;

// ==================== 方法1：直接使用結構體 ====================
void method1_direct_struct()
{
    printf("========== 方法1：直接使用結構體 ==========\n");
    
    Student stu1;
    
    // 初始化學生信息
    strcpy(stu1.name, "李明");
    stu1.student_id = 862103;
    strcpy(stu1.address.city, "台北市");
    strcpy(stu1.address.district, "中山區");
    strcpy(stu1.address.street, "民權東路");
    
    // 訪問數據
    printf("姓名：%s\n", stu1.name);
    printf("學號：%d\n", stu1.student_id);
    printf("地址：%s%s%s\n", stu1.address.city, 
                            stu1.address.district, 
                            stu1.address.street);
    printf("\n");
}

// ==================== 方法2：使用指針和動態內存 ====================
void method2_pointer_dynamic()
{
    printf("========== 方法2：使用指針和動態內存 ==========\n");
    
    // 分配動態內存
    StudentPtr stu2 = (StudentPtr)malloc(sizeof(Student));
    
    if (stu2 == NULL) {
        printf("內存分配失敗\n");
        return;
    }
    
    // 初始化學生信息（使用指針訪問）
    strcpy(stu2->name, "王小芳");
    stu2->student_id = 862104;
    strcpy(stu2->address.city, "新竹市");
    strcpy(stu2->address.district, "東區");
    strcpy(stu2->address.street, "光復路");
    
    // 訪問數據
    printf("姓名：%s\n", stu2->name);
    printf("學號：%d\n", stu2->student_id);
    printf("地址：%s%s%s\n", stu2->address.city, 
                            stu2->address.district, 
                            stu2->address.street);
    
    // 打印結構體大小
    printf("Student結構體大小：%zu 字節\n", sizeof(Student));
    printf("Address結構體大小：%zu 字節\n", sizeof(Address));
    
    // 釋放內存
    free(stu2);
    stu2 = NULL;
    printf("\n");
}

// ==================== 方法3：指針數組（多個學生） ====================
void method3_pointer_array()
{
    printf("========== 方法3：指針數組（多個學生） ==========\n");
    
    int num_students = 3;
    StudentPtr *students = (StudentPtr *)malloc(num_students * sizeof(StudentPtr));
    
    // 初始化3個學生
    for (int i = 0; i < num_students; i++) {
        students[i] = (StudentPtr)malloc(sizeof(Student));
    }
    
    // 第一個學生
    strcpy(students[0]->name, "陳建宏");
    students[0]->student_id = 862105;
    strcpy(students[0]->address.city, "台中市");
    strcpy(students[0]->address.district, "西屯區");
    strcpy(students[0]->address.street, "黎明路");
    
    // 第二個學生
    strcpy(students[1]->name, "黃思琪");
    students[1]->student_id = 862106;
    strcpy(students[1]->address.city, "台南市");
    strcpy(students[1]->address.district, "東區");
    strcpy(students[1]->address.street, "成功路");
    
    // 第三個學生
    strcpy(students[2]->name, "張美麗");
    students[2]->student_id = 862107;
    strcpy(students[2]->address.city, "高雄市");
    strcpy(students[2]->address.district, "左營區");
    strcpy(students[2]->address.street, "民族一路");
    
    // 打印所有學生信息
    for (int i = 0; i < num_students; i++) {
        printf("學生 %d：\n", i + 1);
        printf("  姓名：%s\n", students[i]->name);
        printf("  學號：%d\n", students[i]->student_id);
        printf("  地址：%s%s%s\n", students[i]->address.city,
                                students[i]->address.district,
                                students[i]->address.street);
    }
    
    // 釋放內存
    for (int i = 0; i < num_students; i++) {
        free(students[i]);
        students[i] = NULL;
    }
    free(students);
    students = NULL;
    printf("\n");
}

// ==================== 方法4：正確的指針初始化 ====================
void method4_correct_initialization()
{
    printf("========== 方法4：正確的指針初始化 ==========\n");
    
    StudentPtr stu4 = (StudentPtr)malloc(sizeof(Student));
    
    // 方式A：使用 (*指針) = {...}
    *stu4 = (Student){
        .name = "劉德華",
        .student_id = 862108,
        .address = {
            .city = "基隆市",
            .district = "中山區",
            .street = "港西街"
        }
    };
    
    printf("姓名：%s\n", stu4->name);
    printf("學號：%d\n", stu4->student_id);
    printf("地址：%s%s%s\n", stu4->address.city,
                            stu4->address.district,
                            stu4->address.street);
    
    free(stu4);
    stu4 = NULL;
    printf("\n");
}

// ==================== 輔助函數：打印學生信息 ====================
void print_student(StudentPtr stu, int index)
{
    printf("學生 %d 信息：\n", index);
    printf("  姓名：%s\n", stu->name);
    printf("  學號：%d\n", stu->student_id);
    printf("  地址：%s%s%s\n\n", stu->address.city,
                                stu->address.district,
                                stu->address.street);
}

int main(void)
{
    printf("====== 嵌套結構體示例：學生信息管理 ======\n\n");
    
    method1_direct_struct();
    method2_pointer_dynamic();
    method3_pointer_array();
    method4_correct_initialization();
    
    printf("====== 所有示例完成 ======\n");
    
    return 0;
}
