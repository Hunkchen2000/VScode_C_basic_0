#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int main(int argc, char **argv)
{
  // printf("The number of bits in a byte %d", FLT_MIN_10_EXP);
   printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
   printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
   printf("The maximum value of UNSIGNED CHAR =  %d\n", UCHAR_MAX);
   printf("The minimum value of SHORT INT =  %d\n", SHRT_MIN);
   printf("The maximum value of SHORT INT =  %d\n", SHRT_MAX); 
   printf("The minimum value of INT = %d\n", INT_MIN);
   printf("The maximum value of INT = %d `\n", INT_MAX);
   printf("The minimum value of CHAR = %d\n", CHAR_MIN);
   printf("The maximum value of CHAR = %d\n", CHAR_MAX);
   printf("The minimum value of LONG = %ld\n", LONG_MIN);
   printf("The maximum value of LONG = %ld\n", LONG_MAX);
	return 0;
}


//The number of bits in a byte 8The minimum value of SIGNED CHAR = -128
//The maximum value of SIGNED CHAR = 127
//The maximum value of UNSIGNED CHAR =  255
//The minimum value of SHORT INT =  -32768
//The maximum value of SHORT INT =  32767
//The minimum value of INT = -2147483648
//The maximum value of INT = 2147483647
//The minimum value of CHAR = -128
//The maximum value of CHAR = 127
//The minimum value of LONG = -2147483648
//The maximum value of LONG = 2147483647
//請按任意鍵繼續 . . .

//在C99中包括的特性有：
//
//增加了對編譯器的限制，比如源始碼每行要求至少支持到 4095 字節，變量名函數名的要求支持到 63 字節（extern 要求支持到 31）。
//增強了預處理功能。例如：
//巨集支持取可變參數 #define Macro(...) __VA_ARGS__
//使用巨集的時候，允許省略參數，被省略的參數會被擴展成空串。
//支持 // 開頭的單行注釋（這個特性實際上在C89的很多編譯器上已經被支持了）
//增加了新關鍵字 restrict, inline, _Complex, _Imaginary, _Bool
//支持 long long, long double _Complex, float _Complex 等類型
//支持不定長的數組，即數組長度可以在運行時決定，比如利用變量作為數組長度。聲明時使用 int a[var] 的形式。不過考慮到效率和實現，不定長數組不能用在全局，或 struct 與 union 。
//變量聲明不必放在語句塊的開頭，for 語句提倡寫成 for(int i=0;i<100;++i) 的形式，即i 只在 for 語句塊內部有效。
//允許採用（type_name）{xx,xx,xx} 類似於 C++ 的構造函數的形式構造匿名的結構體，即複合文字特性。
//初始化結構體的時候允許對特定的元素賦值，形式為：
//struct test{int a[3]，b;} foo[] =  { [0].a = {1}, [1].a = 2 };
//struct test{int a, b, c, d;} foo =  { .a = 1, .c = 3, 4, .b = 5 };  // 3,4 是? .c,.d ?值的
//格式化字符串中，利用 \u 支持 unicode 的字符。
//支持 16 進位的浮點數的描述。
//printf scanf 的格式化串增加了對 long long int 類型的支持。
//浮點數的內部數據描述支持了新標準，可以使用 #pragma 編譯器指令指定。
//除了已有的 __line__ __file__ 以外，增加了 __func__ 得到當前的函數名。
//允許編譯器化簡非常數的表達式。
//修改了 / % 處理負數時的定義，這樣可以給出明確的結果，例如在C89中-22 / 7 = -3, -22 % 7 = -1，也可以-22 / 7= -4, -22 % 7 = 6。 而C99中明確為 -22 / 7 = -3, -22 % 7 = -1，只有一種結果。
//取消了函數返回類型默認為 int 的規定。
//允許在 struct 的最後定義的數組不指定其長度，寫做 [](flexible array member)。
//const const int i 將被當作 const int i 處理。
//增加和修改了一些標準頭文件，比如定義 bool 的 <stdbool.h> ，定義一些標準長度的 int 的 <inttypes.h> ，定義複數的 <complex.h> ，定義寬字符的 <wctype.h> ，類似於泛型的數學函數 <tgmath.h>， 浮點數相關的 <fenv.h>。 在<stdarg.h> 增加了 va_copy 用於複製 ... 的參數。<time.h> 里增加了 struct tmx ，對 struct tm 做了擴展。
//輸入輸出對寬字符以及長整數等做了相應的支持。[3]
//用於x86架構的GCC,Clang和其它一些商業編譯器(如IAR Systems,ICC)現支持C99的全部特性[4]，而微軟和Borland支持C99的部分特性[5]。