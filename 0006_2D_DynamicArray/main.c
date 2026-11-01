
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Return_2D_Pointer_malloc(int row, int col);

int main(int argc, char **argv)
{
int row=8;//Y
int col=10;//X

printf("hunkchen array back test.....\n");
Return_2D_Pointer_malloc(row,col);
return 0;
}

void Return_2D_Pointer_malloc(int row, int col)
{

int(*ptr3)[col] = (int(*)[col])malloc(row*col* sizeof(int*));//

for(int x=0;x<row;x++)
    {
for(int y=0;y<col;y++)
    {
       *(*(ptr3+x)+y)=x*y;

    }
}

for(int x=0;x<row;x++)
{
    for(int y=0;y<col;y++)
    { 
         printf("%3d",*(*(ptr3+x)+y));
    } 
    printf("\n");
}

   	printf("\n--------------free ptr3------------------------\n");  
     for (int i = 0; i < row; i++) 
         {
          free(ptr3[i]); // 先對ROW釋放記憶空間
        }
         free(ptr3);     //直接釋放col記憶空間
         ptr3 = NULL;       //把指標指向NULL
}
