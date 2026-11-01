#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap0(int x,int y)//call_by_value
{
      int temp =x; // 將 a 指標指向的值存入 temp
     x = y;       // 將 b 指標指向的值給 a
      y=temp;     // 將 temp 的值給 
    }


void swap1(int *a, int *b)//call_by_address
{
    int temp = *a; // 將 a 指標指向的值存入 temp
    *a = *b;       // 將 b 指標指向的值給 a
    *b = temp;     // 將 temp 的值給 b
}

int main(int argc, char **argv)
{
    
    int x0=100;
    int y0=200;
    
    
    int x1 = 5;
    int y1 = 10;
    
    printf("交換前: x0 = %d, y0 = %d\n", x0, y0);
    printf("交換前: x1 = %d, y1 = %d\n", x1, y1);
    
     // 傳入變數的記憶體位址 (&)
    
    swap0(x0,y0);
    
    swap1(&x1, &y1);

    printf("交換後: x0=  %d, y0 = %d\n", x0, y0);
    printf("交換後: x1 = %d, y1 = %d\n", x1, y1);
    
	return 0;
}
