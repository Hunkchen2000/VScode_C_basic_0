#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int* getrandom(void); //1D_ARRAY
int** getrandomCX(void);//2D_ARRAY
 
int main(int argc, char **argv) 
{
  int i, x;
  int *p = getrandom();
  int **T = getrandomCX();

//  char stringx;
 //s_get *()

//   printf(" 回傳動態一維陣列 \n");
//  for (i = 0; i < 10; ++i) 
//	  
//  {
//    printf("*(p+%d) :***** %d\n", i, *(p + i));
//    printf("ptr address %p\n",*(p + i));//列印指標位址
//  }
  
   printf(" 回傳動態二維陣列 \n");
  for (i = 0; i < 10; ++i) 
	   {
    for (x = 0; x < 5; ++x) 
	{
     // printf("i=%d  x=%d  *T=%d", i, x, *(*(T+i)+x));.
        printf("*T=%d ",*(*(T+i)+x));
     // printf("\n");
    }
    printf("\n");
  }
  free(p);
  
  
  for (i = 0; i < 10; ++i) 
  {
    free(T[i]);
  }
  free(T);
  return 0;
}
 
int* getrandom(void) 
{
  int i;
  int *r = (int*) malloc(sizeof(int) * 10);
  srand((unsigned) time(NULL));
  for (i = 0; i < 10; ++i)
 {
    r[i] = rand() % 100 + 1;
  }
  return r;
}
 
int** getrandomCX(void)
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
      rx[i][x] = i*x;
    }
  }
  return rx;
}