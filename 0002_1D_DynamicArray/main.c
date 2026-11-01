#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ROW 4
#define COL 3
void showarray1(int *ptr);
int *getRandom(); //Retuen array 
void getRandom2(int *arry);
int *Dynamical_memory(int *ptrx);//Dynamical function//
int main(void)
{
   srand((unsigned)time(NULL));  // 只在程序開始調用一次
   int array1[10]={11,24,36,42,51,21,17,64,12,71};
   int array2[10]={0};
   int *ptrx=(int*)malloc(sizeof(int)*10);
   int *p1;
   //int *p2;
   if (ptrx == NULL) {
        printf("\n");
        return 1;
    }
     printf("_______________第一種一維陣列______________________________\n");
     showarray1(array1);
     printf("_______________第二種一維陣列使用指標________________________\n");

    p1 = getRandom();//note//
    for (int i = 0; i < 10; i++ )
   {
        printf("getRandom= *(p  + [%d]) : %d\n", i, *(p1+i) );
   }
    printf("_______________第三種一維陣列使用指標帶入陣列__________________\n");
     getRandom2(array2);
    for(int x=0;x<=9;x++)
    {
      printf("main fucntion getRandom2=%d\n",array2[x]);
    }

    printf("_______________第四種一維陣列使用指標帶入_____________________\n");
     int *ptry=Dynamical_memory(ptrx); 
      for(int loop=0;loop<10;loop++)   
      {
           printf("The loop %d *ptry==%d\n", loop ,*(ptry+loop));
      }
       free(ptry);  // 釋放動態分配的內存

  //  free(ptrx); //
//  printf("____________________\n");
//    for(int x=0;x<=9;x++)
//	   {
//		   printf("pointer=%d\n", *(ptrx+x));
//		   }	


 
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

void showarray1(int *ptr) 
{	

       for(int x=0;x<=9;x++)
	   {
		   printf("pointer=%d\n", *(ptr+x));
		   }	
		  // free(ptr);
}
int *getRandom()
{
   static int  r[10]; 
   for (int i = 0; i < 10; ++i)
   {
      r[i] = rand() % 100;
      printf("%d\n", r[i] );
   }
   return r;
}
void getRandom2(int *arry)
{
 for (int i = 0; i < 10; ++i)
   {
      arry[i] = rand() % 100;
      printf("getRandom2 %d\n", arry[i] );
   }
}

int *Dynamical_memory(int *ptrx)
{
	for(int x=0;x<10;x++)
	{
	  *(ptrx+x)=x*x*x;
	}
   return ptrx;
}