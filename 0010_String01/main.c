#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void strings(char *p);
int main(void)
{
    char *PS1="hunkchen2000@gmail.com";
    char *PS2="hunkchen2000@gmail.com";

    // char name[20];
    // fgets (name, 20, stdin);
    // puts(name);
    strings(PS1);
    if(strcmp(PS1,PS2)==0)
    {
      printf("PS1=PS2\n");

    }
    else{
        printf("PS1!=PS2\n");
    }
    return 0;
}
void strings(char *p)
{

  printf("%s\n", p);
}
//-----------------------------------------------------------------------//
//num=0x7ffc4155ee50
//&num=0x7ffc4155ee50
//*num=0x7ffc4155ee50
//num[0]=0x7ffc4155ee50
//num[1]=0x7ffc4155ee60
//num[2]=0x7ffc4155ee70
//&num[0]=0x7ffc4155ee50
//&num[1]=0x7ffc4155ee60
//&num[2]=0x7ffc4155ee70
