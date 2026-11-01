#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ROW 4 //--Y Axis
#define COL 3 //--X Axis
void showarray1(int *ptr);
int main(void)
{
                //前Y後X
      int array2[ROW][COL] = {{10, 20, 30}, 
                             {40, 50, 60},
                             {70, 80, 90},
                             {100, 110,120},}; 
      
      int (*prt)[3]=array2;
 
        for (int i = 0; i <ROW; i++) //心法,先跑Y Axis後跑X Axis
               {
                     for (int j = 0; j <COL; j++) 
                          {
                               printf("%d ", *(*(prt+i)+j)); //相同效果
                           }
                          printf("\n");
    }
//  int arr[2][3] = {{10, 20, 30}, {40, 50, 60}}; 
//  int **ptr=(int**)malloc(sizeof(int*)*3)=arr;
//  printf("=====%d\n", *(*(ptr+0)+0));
//  printf("%d\n", 10/8);
//  printf("%d\n", 10%8);
//  printf("____________________\n");
//
//   for(int x=0;x<=9;x++)
//	   {
//		   printf("pointer=%d\n", *(ptr+x));
//		   }	
//           
           
  //  free(ptrx); //動態記憶體已經指向一個陣列不要釋放free
  //這個警告意味著你的程式試圖釋放（free() 或 delete）
  //一個不是由動態記憶體配置（如 malloc、calloc、new）產生的物件或記憶體位址。這會導致未定義行為
//  printf("____________________\n");
//    for(int x=0;x<=9;x++)
//	   {
//		   printf("pointer=%d\n", *(ptrx+x));
//		   }	

//~~~以下是另外一種作法~~~// 
 
//   int **ptr2;
//   ptr2=(int**)malloc(sizeof(int*)*15);
//   ptr2=array2[0]; 
//   printf("=====%d\n", *(*(ptr2+0)+0));
// 
//   int (*ptrx2)[5]=array2;
//	char *str="NULL";
//	str = (char *) malloc(15);
//	strcpy(str, "yiibai");
//	 
//	 
//	printf("%s\n",str);
//	 
//	printf("the == %d\n",*ptr+0);
//	printf("the == %d\n",*ptr+1);
//	printf("the == %d\n",*ptr+2);
//	printf("the == %d\n",*ptr+3);
//	printf("the == %d\n",*ptr+4);

	return 0;
}
//int arr[2][3] = {{10, 20, 30}, {40, 50, 60}}; 
//int (*p)[3] = arr;
//int arr[1][2][3] = {{{10, 20, 30}, {40, 50, 60}}}; 
//int (*p)[2][3] = arr;
//int arr1[2][3] = {{10, 20, 30}, {40, 50, 60}}; 
//auto p1 = arr1;
//
//int arr2[1][2][3] = {{{10, 20, 30}, {40, 50, 60}}}; 
//auto p2 = arr2;

//void showarray1(int *ptr) //?????箔??蝬剝?????
//{	
//
//       for(int x=0;x<=9;x++)
//	   {
//		   printf("pointer=%d\n", *(ptr+x));
//		   }	
//		  // free(ptr);
//}