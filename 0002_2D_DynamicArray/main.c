#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ROW 4 //-Y Axis
#define COL 5 //-X Axis
void Creatandshowarray1(int **ptr);
int **Dynamical_memory_2_Dimensions(int **ptrA);//Dynamical_2_Dynamical_2_Dimensions function//
int **getrandomCX();
int main(void)
{
    int **T = getrandomCX();  // 在 main() 中調用
    
	printf("_______________第一種二維動態記憶體配置陣列___________________________");
    int **ptr=(int**)malloc(sizeof(int*)*ROW);//配置二維動態記憶體空間
    Creatandshowarray1(ptr);


    printf("_____________第二種二維動態記憶體配置陣列_________________________");
    int **ptxA=(int**)malloc(sizeof(int*)*5);//Dynamical_2_Dimensions Memory Allocation/
    int **ptrB=Dynamical_memory_2_Dimensions(ptxA);
   
   for(int loopx=0;loopx<5;loopx++)
   {
	  for(int loopy=0;loopy<3;loopy++)
        {
    	      printf("Two Dim return function X=>%d, Y=>%d *ptrB===%d\n", loopx,loopy,*(*(ptrB+loopx)+loopy));
        }
		       printf("\n");
   }
      for(int x=0;x<5;x++)
    {
  	  free(ptrB[x]);
    }
     free(ptrB);


 for (int i = 0; i < 10; ++i) 
	   {
    for (int x = 0; x < 5; ++x) 
	{
      printf("===i=%d  x=%d ==>=%d\n",i,x, *(*(T+i)+x));
    }
  }
  for (int i = 0; i < 10; i++) 
  {
    free(T[i]);
  }
  free(T);






	return 0;
}
void Creatandshowarray1(int **ptr) //
{	
	for(int x=0;x<ROW;x++)
	{
		ptr[x]=(int*)malloc(sizeof(int)*COL);
	}
  for(int x=0;x<ROW;x++)
  {
	  for(int y=0;y<COL;y++)
	  {
		      *(*(ptr+x)+y)=x*y;
		  }
	  }
	
	for(int x=0;x<ROW;x++) 
     {
         for(int y=0;y<COL;y++)
           {
             printf("%3d",*(*(ptr+x)+y));
		   }
           printf("\n");
	}
	
//-------------------釋放二維記憶體空間----------------------//
	 for (int i = 0; i < ROW; i++) {
        free(ptr[i]);
    }
    free(ptr);
}

int **Dynamical_memory_2_Dimensions(int **ptxA)
{  
	for(int x=0; x<5;x++)
	{
		ptxA[x]=(int*)malloc(10*sizeof(int));
	}

for(int x=0;x<5;x++)
  {
	  for(int y=0;y<3;y++)
	  {
		  *(*(ptxA+x)+y)=x*y;
	  }
  } 
     return ptxA; 
   }

int** getrandomCX()  // 函數定義在前面聲明之後
 {
  int i, x;
  int **rx = (int**) malloc(sizeof(int*) * 10);
  for (i = 0; i < 10; ++i)
 {
    rx[i] = (int*) malloc(sizeof(int) * 5);
  }
  srand((unsigned)time(NULL));
  for (i = 0; i < 10; ++i) 
	  {
    for (x = 0; x < 5; ++x) 
	{
      rx[i][x] = rand() % 100;
    }
  }
  return rx;
}
