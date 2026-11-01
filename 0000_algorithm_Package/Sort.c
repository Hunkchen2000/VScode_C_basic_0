#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 
void bubble_sort(int *ptr, int size)
 {
  for (int i = 0; i < size; ++i) 
	  {
    for (int j = 0; j < i; ++j) 
		{
      if (*(ptr+j) > *(ptr+i))
           {
            int temp =*(ptr+j);
            *(ptr+j) =*(ptr+i);
            *(ptr+i) = temp;
           }
        }
	  }
   }
 //-----------------------------------------------------//  
void showarray(int *ptr, int size )
  {
	  
	  for(int x=0;x<size;x++)
	  {
		  if((x%10==0)&&x!=0)
		  printf("\n");		

	    printf("  %d",*(ptr+x));
	  }
    printf("\n");		
  }
//==================================================================//
void quickSort(int number[], int left, int right) 
  { 
    if(left < right) {  //number[10]={6,1,3,9,2,4,7,5,7,10};
        int s = number[(left+right)/2]; //4
        int i = left - 1; 
        int j = right + 1; 
 
 while(1) { 
            while(number[++i] < s) ;  // 向右找 
            while(number[--j] > s) ;  // 向左找 
            if(i >= j) 
                break; 
            SWAP(number[i], number[j]); 
        } 
 
        quickSort(number, left, i-1);   // 對左邊進行遞迴 
        quickSort(number, j+1, right);  // 對右邊進行遞迴 
    } 
} 