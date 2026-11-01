#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 50
typedef struct Toyota 
{
 char    name[10];
 char    color[10];
 double  volume;
 double  price;
}hunkchen2000;

typedef struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Book;
/*-----------------------Nested Struct-----------------*/
struct namespace_test
{
    char namespace[LEN];
    };

struct student
{
    struct namespace_test NAME;
    int number;
    char name[LEN];
};
typedef struct student dnode;      
typedef dnode *Student_dlink;   
int main(void)
{
    //---------------------使用指標址向Struct---------------------//
	struct Toyota hunkchen2000;
    struct Toyota *ptrStruct =&hunkchen2000;
    strcpy(hunkchen2000.name, "hunkchen"); 
    strcpy(hunkchen2000.color, "Blue"); 
    hunkchen2000.price=100;
    hunkchen2000.volume=50;
    printf("Sizeof(Toyota)=%zu\n",sizeof(hunkchen2000));/*在 C 語言中，%zu 是用來格式化輸出 size_t 型別（無號整數）的佔位符*/
    printf(" name %s\n",hunkchen2000.name);
    printf(" COLOR %s\n",hunkchen2000.color);
    printf(" price %2f\n",hunkchen2000.price);
    printf(" Volume %2f\n",hunkchen2000.volume);
	strcpy((*ptrStruct).name, "hunkchen"); 
	strcpy((*ptrStruct).color, "Blue"); 
	ptrStruct->price=100;
	ptrStruct->volume=50;
	printf(" name %s\n",ptrStruct->name);
	printf(" COLOR %s\n",ptrStruct->color);
	printf(" price %f\n",ptrStruct->price);
	printf(" Volume %f\n",ptrStruct->volume);
//-------------------typede 建立指標動態記憶體---------------------------------//
    Book *book=(Book*) malloc(sizeof(Book));//建立新節點;
    book->book_id=1001;
    strcpy(book->title,"Math way calculus");
    strcpy(book->author,"Jaent");
    strcpy(book->subject,"Math");
    printf("TITLE %5s\n",book->title);
    printf("name %5s\n",book->author);
    printf("Category %5s\n",book->subject);
    printf("book_id %5d\n",book->book_id);
//-------------------typede 一般用法---------------------------------//
    // book.book_id=1001;
    // strcpy(book.title,"Math way calculus");
    // strcpy(book.author,"Jaent");
    // strcpy(book.subject,"Math");
    // printf("TITLE %5s\n",book.title);
	// printf("name %5s\n",book.author);
    // printf("Category %5s\n",book.subject);
    
  //-------------------嵌套Struct test----------------------
       Student_dlink NTOU_STUDENT;
       NTOU_STUDENT=(Student_dlink)malloc(sizeof(dnode));
               (*NTOU_STUDENT)=(dnode){{"SSSSSS"},
                                   862103,
                                  "StudentName"};

    //    strcpy(NTOU_STUDENT->NAME.namespace,"Nation Taiwan");
    //    strcpy(NTOU_STUDENT->name,"Mail Machine");
    //    NTOU_STUDENT->number=1000;
       printf("NAME=%s\n",NTOU_STUDENT->NAME.namespace);
       printf("name=%s\n",NTOU_STUDENT->name);
       printf("%d\n",NTOU_STUDENT->number);
    //    NTOU_STUDENT={{"Ewen2000"},
    //                  862103,
    //                  "Nation Taiwan Ocean Universtry"
    //                  };
    // struct student *ptr =&hunkchen;
    // printf("name=%s\n",ptr->NAME.namespace);
    // printf("name=%s\n",ptr->name);
    // printf("numbe=%d\n",ptr->number);
	return 0;
}
