#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//int* ints(int, int);
int **TWOARRAY(void); 
int main(int argc, char **argv)
{  
	int **twoarr = TWOARRAY();
		  
     for(int x=0;x<5;x++) 
	        {   
		       for(int y=0;y<4;y++) 
		         {
			       printf("%d  ",*(*(twoarr+x)+y));
		         }
		      printf("\n");  
		   }
	printf("\n--------------free twoarr------------------------\n");  
    for(int i=0;i<5;i++)
    {
        free(twoarr[i]);
        
        }
         free(twoarr);
    
	//另外一種方式用指標	   
//		      int size=5;
//            int init=1;
//		    int *arr = ints(size, init);
//			for(int x=0;x<4;x++)
//			{
//				printf("%2d\n",*(arr+x));
//				}
    return 0;
} 

//int *TWOARRAY(void) //不能用
//{
//	 int **ptr2=(int**)malloc(5*sizeof(int*));
//    	 static int number[5][4]={{1,2,3,4},
//			                      {5,6,7,8},
//								  {9,9,9,9},
//								  {7,7,7,7},
//			                      {9,10,11,12}};
//								  								  
//		for(int x=0;x<5;x++)
//	        { 
//		       for(int y=0;y<4;y++) 
//		         {
//				   ptr2[x][y]=number[x][y];
//		         }
//		        
//		   }
//		   
//		   							  								  
//		for(int x=0;x<5;x++)
//	        { 
//		       for(int y=0;y<4;y++) 
//		         {
//				   printf("%2d " ,ptr2[x][y]);
//		         }
//	           printf("\n");	        
//		   }
//	        return *ptr2;  
//}



//
//int* ints(int size, int init);
//int* ints2(int x, int y);
// 
//int *arrayreturn_test()
//{
//	static int ra[5];
//	
//    for(int x=0;x<5;x++) 
//		{
//          ra[x]=12;
//		
//        }  
//      return ra;
//}
//
//int main(int argc, char **argv)
//{
//	
////  int *getArray;
////	getArray= arrayreturn_test();
////    
//	 int *arr = ints(3, 5);
//	 
//	 for(int i = 0; i < 3; i++) 
//	  {
//        printf("arr[%d] = %d\n", i, arr[i]);
//	  }
//	 
//	  int a=10,b=12;
//	  int *pointerA=ints2(a,b);
//	  printf("%d\n",*pointerA); 
//	
//	
//	return 0;
//}
//
// int* ints(int size, int init) 
// {
//    int *arr = malloc(size * sizeof(int));
//    for(int i = 0; i < size; i++) 
//		{
//          arr[i] = init;
//        }
//    return arr;
//}
//
//
// int* ints2(int x, int y) 
// {
//    int *A= malloc(sizeof(int));//在程式中以動態方式配置一個 int 型態大小的記憶體
//    *A=x+y;
//    return A;
//}  
//
