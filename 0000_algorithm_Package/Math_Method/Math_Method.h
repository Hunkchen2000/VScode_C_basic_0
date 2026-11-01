#ifndef _MathMethod_
#define _MathMethod_

/* 以遞迴方式計算費氏數列的第 n 項 */
long long int fibonacci(int n);

/* 求兩數的最大公因數（Greatest Common Divisor，簡稱 GCD） */
int get_gcd(int a, int b);

/* 求兩數的最小公倍數（Least Common Multiple，簡稱 LCM），回傳結果 */
int get_lcm(int a, int b);

/* 分數運算：輸入 a/b 與 c/d 兩個分數，結果會約分後直接印出 */
void add(int a,int b,int c,int d);                 /* 分數加法 a/b + c/d */
void mul(int a,int b,int c,int d);                 /* 分數乘法 a/b * c/d */
void sub(int a,int b,int c,int d);                 /* 分數減法 a/b - c/d */
void division(int a,int b,int c,int d);            /* 分數除法 a/b / (c/d)，c 為 0 時顯示錯誤 */

/* 將分數 a/b（分子/分母）約分後印出 */
void yuefen(int a,int b);

/* 重複宣告 get_lcm（與上方相同，保留不影響編譯） */
int get_lcm(int a, int b);

/* 在陣列中找出最大值，回傳指向最大值的指標（p 為陣列，n 為元素個數） */
int *FindMax(int *p, int n);

/* 整數四則運算 */
int ADD(int a,int b);                              /* 加法：a + b */
int SUB(int a,int b);                              /* 減法：a - b */
int MUL(int a,int b);                              /* 乘法：a * b */
int DIV(int a,int b);                              /* 除法：a / b，b 為 0 時顯示錯誤並回傳 0 */

/* 交換兩個整數的值 */
void swap(int *a, int *b);

/* 以氣泡排序法將陣列 arr 由小到大排序（n 為元素個數） */
void sortArray(int arr[], int n);

/* 求陣列的中位數（會先排序；元素個數為偶數時取中間兩數平均） */
float findMedian(int arr[], int n);

/* 找出陣列中的最大值與最小值，結果透過 max、min 指標回傳 */
void max_min(int a[], int n, int *max, int *min);

//void finMaxMin(int array[],int *max,int *min);
#endif
