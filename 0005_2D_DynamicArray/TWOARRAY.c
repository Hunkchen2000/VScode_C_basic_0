#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int **TWOARRAY(void)
{
	 //int **ptr2=(int**)malloc(3*sizeof(int*));
	 // int **ptr2=(int**)malloc(5*sizeof(int*));
     // int **rx = (int**) malloc(sizeof(int*) * 10);
    
    int **ptr2=(int**)malloc(5*sizeof(int*));
    for(int i = 0; i < 5; i++) 
		{
           ptr2[i] = malloc(4*sizeof(int));
        }
	 int number[5][4]={{1,2,3,4},
                       {5,6,7,8},
                       {9,9,9,9},
                       {7,7,7,7},
                       {9,10,11,12}};
   for(int x=0;x<5;x++)
	        { 
		       for(int y=0;y<4;y++) 
		         {
				   ptr2[x][y]=number[x][y];
		         }
		   }
//		for(int x=0;x<5;x++)
//	        { 
//		       for(int y=0;y<4;y++) 
//		         {
//				   printf("%2d " ,ptr2[x][y]);
//		         }
//	           printf("\n");	        
//		   }
	       //  return number;  
		       return ptr2;
}

//int* ints(int size, int init) {
//    int *arr = malloc(size * sizeof(int));
//    for(int i = 0; i < size; i++) 
//		{
//        arr[i] = init*i;
//    }
//    return arr; 
//}