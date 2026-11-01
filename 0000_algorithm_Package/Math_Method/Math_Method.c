
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Math_Method.h"
long long int fibonacci(int n)
{
    // 基礎情況
    if (n <= 1)
        return n;
    // 遞迴情況
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int get_gcd(int a, int b) //求最大公約數（Greatest Common Divisor，簡稱 GCD）
{
    while (b != 0)
     {
        int temp = a % b;
       // printf("temp=%d\n",temp);
        a = b;
        b = temp;
    }
    return a;
}
int get_lcm(int a, int b) ////取出最小公倍數
 {
    if (a == 0 || b == 0) return 0;
    return ((a / get_gcd(a, b)) * b);
}
void add(int a,int b,int c,int d)					/*定義加法函數*/
{
  int u1,u2,v=get_lcm(b,d),fz1,fm1;
  u1=v/b*a;
  u2=v/d*c;
  fz1=u1+u2;
  fm1=v;
  yuefen(fz1,fm1);
}
void mul(int a,int b,int c,int d)					/*定義乘法函數*/
{ 
  int u1,u2;
  u1=a*c;
  u2=b*d;
  yuefen(u1,u2);
}
void sub(int a,int b,int c,int d)					/*定義減法函數*/
{   
  int u1,u2,v=get_lcm(b,d),fz1,fm1;
  u1=v/b*a;
  u2=v/d*c;
  fz1=u1-u2;
  fm1=v;
  yuefen(fz1,fm1);
}
void division(int a,int b,int c,int d)		/*定義除法函數*/
{
     if (c == 0) {
        printf("Error: denominator cannot be zero\n");
        return;
    }
  int u1,u2;
  u1=a*d;
  u2=b*c;
  yuefen(u1,u2);
}
void yuefen(int fz,int fm)					/*定義約分函數*/
{ 
  int s=get_gcd(fz,fm);
  fz/=s;
  fm/=s;
  printf("the result is %d/%d\n",fz,fm);
}
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
void get_LCM(int a, int b) ////取出最小公倍數

    {
      int lcm = (a * b) / get_gcd(a, b);
      printf("The LCM of %d and %d is: %d\n", a, b, lcm);
    }
int *FindMax(int *p, int n)
{
    int i,  *max;
    max = p;
    for (i = 0; i < n; i++)
        if (*(p + i) >  *max)
            max = p + i;
    return max;
}
int ADD(int a,int b)/*定義加法函數*/
{
  return a+b;
}
int SUB(int a,int b)/*定義減法函數*/
{
  return a-b;
}
int MUL(int a,int b)/*定義乘法函數*/
{
  return a*b;
}
int DIV(int a,int b)/*定義除法函數*/
{
  if (b == 0) {
        printf("Error: denominator cannot be zero\n");
        return 0; // 或者返回一????
    }
  return a/b;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
float findMedian(int arr[], int n)
 {
    sortArray(arr, n);

    if (n % 2 == 1) {
        return arr[n / 2];
    } else {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
}
int *Fisher_Yates_Random(int MAX_NUM,int PICK_COUNT)
{
  int *Fisher_Yates_Random=(int*)malloc(sizeof(int)*PICK_COUNT);
  int *pool=(int*)malloc(sizeof(int)*MAX_NUM);
    // 初始化陣列 1 到 10000
    for (int i = 0; i < MAX_NUM; i++)
     {
        pool[i] = i + 1;
        printf("pool[%d]=%d\n",i,pool[i]);
     }
    printf("_______________________________\n");
    // 設定亂數種子
    srand((unsigned int)time(NULL));
    // Fisher-Yates 洗牌演算法（只洗前 100 個位置就夠了）
    for (int i = 0; i < PICK_COUNT; i++)
     {
        int r = i + rand() % (MAX_NUM - i);//0~MAX_NUM的隨機數//將前面的隨機結果加上 i，目的是將整個隨機範圍「向右平移」i 個單位。
       // printf("r=%d\n",r);//經過平移後，r 的最終數值範圍會落在 i 到 MAX_NUM - 1 之間
        // 交換 pool[i] 與 pool[r]
        int temp = pool[i];
         pool[i]=pool[r];
         pool[r] = temp;
    }
    // 印出前 100 個隨機不重複的數字
    printf("隨機產生的 100 個不重複數字（範圍 1~10000）：\n");
    for (int i = 0; i < PICK_COUNT; i++) {
        //printf("%d ",pool[i]);
        if ((i + 1) % 10 == 0) { // 每 10 個換行一次
            printf("\n");
        }
    }
    for (int x = 0; x < PICK_COUNT; x++)
    {
      *(Fisher_Yates_Random+x)=pool[x];
    }
    free(pool);
    // for(int x=0;x<=99;x++)
    //       printf("%d\n",*(Fisher_Yates_Random+x));
   return  Fisher_Yates_Random;
} 
void max_min(int a[], int n, int *max, int *min)//尋找陣列中最大和最小,記得要設定int max, min進去然後得到max and min的value
{
  int *p;
    *max = *min =*a;
    for (p = a + 1; p < a + n; p++)
        if (*p >  *max)
            *max =  *p;
        else if (*p <  *min)
            *min =  *p;
}
// void finMaxMin(int array[], int *max, int *min)
// {
//  for (int i = 1; i < 10; i++)
//     {
//         if (array[i] > max)
//             max = array[i];

//         if (array[i] < min)
//             min = array[i];
//     }
//     printf("最大值 = %d\n", max);
//     printf("最小值 = %d\n", min);
// }
