#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include "1DArray_Return.h"
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