#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <complex.h>


#define ROW 5
#define COL 4
//void useptr_to_2D_array(int Array[][COL]);
void useDynamic2D_to_2D_array(int Array[][COL],int row, int Columns);

int main(int argc, char **argv)
{

	int Array[ROW][COL]={{1,2,3,4},
	                     {5,6,7,8},
			 		     {9,10,11,12},
					     {11,12,13,15},
						 {16,17,18,19}};
	
	int row=(sizeof(Array)/sizeof(int))/(sizeof(Array[0])/sizeof(int));//計算陣列COL個數	5
	
    int Columns=sizeof(Array[0])/sizeof(int); //計算陣列ROW個數		4 

	 printf("Columns=%d\n",Columns);
	 printf("Row=%d\n",row);
	 
	// useptr_to_2D_array(Array);
	 useDynamic2D_to_2D_array(Array, row, Columns);
	
	return 0;
}

//void useptr_to_2D_array(int Array[][COL] )
//{
//int (*ptr2D)[4]=Array; //4是ROW
////    printf("%3d\n",*(*(ptr2D+0)+0));
//
//		for(int x=0;x<ROW;x++)
//		{
//			for(int y=0;y<COL;y++)
//			{
//			 printf("%3d",*(*(ptr2D+x)+y));
//			}
//			printf("\n");
//		} 
//
//}

void useDynamic2D_to_2D_array(int Array[][COL],int row, int Columns)
{
//     long long int x=0;
	
	int **ptr2D=(int**)malloc(sizeof(int*)*row);//建立二維動態陣列	
	for(int x=0;x<ROW;x++)
	{
		ptr2D[x]=(int*)malloc(sizeof(int)*Columns);
		
	}
	
	for(int x=0;x<row;x++)
	{
		for(int y=0;y<Columns;y++)
		{
	     
		  *(*(ptr2D+x)+y)=Array[x][y]	;
		}
		printf("\n");
	}
	
	
	for(int x=0;x<row;x++)
	{
		for(int y=0;y<Columns;y++)
		{
	     
		 printf("%3d", *(*(ptr2D+x)+y));
		}
		printf("\n");
	}
	
	

}