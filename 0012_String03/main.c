#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define STLEN 10
#define LEN  50
char *s_gets(char *st, int n);
//fgets()是為了改善gets()函數,
int main(void)
{
     char Email[STLEN];
     char name[LEN]={0}; // 宣告大小為 100 的字元陣列來存放字串
     char *ptr=name;
   //  char *ptr = str; // 將指標 ptr 指向陣列的首位址
     //char name[STLEN];
     printf("Enter Email\n");
     while(fgets(Email,STLEN,stdin)!=NULL && Email[0]!='\n')
            fputs(Email,stdout);
     puts("Done");
    // gets_s(name,STLEN); //這個編譯器不支援gets_s();不知道是作業系統的問題還是怎樣
     //有空用Linux試試看
     printf("請輸入字串：");
    // 使用 fgets 安全讀取字串，第一個參數為指標（陣列名即為指標）

       s_gets(name,LEN);
      printf("%s\n",name);
      printf("ptr=%c\n",*(ptr+0));
      printf("ptr=%c\n",*(ptr+1));
      printf("ptr=%c\n",*(ptr+2));
      printf("ptr=%c\n",*(ptr+3));
      printf("ptr=%c\n",*(ptr+4));

      printf("%zu\n",strlen(name));
      
       

      for(int x=strlen(name);x>=0;x--)
              printf("%c",name[x]);        

	return 0;
}
char *s_gets(char *st, int n)
{
    char * ret_val;
    int i=0;
    ret_val=fgets(st,n , stdin);
    if(ret_val)
    {
        while(st[i]!='\n' && st[i]!='\0')
            i++;
        if(st[i]=='\n')
           st[i]='\0';
        else
            while(getchar()!='\n')
                continue;
        }
         return ret_val;
    
    } 