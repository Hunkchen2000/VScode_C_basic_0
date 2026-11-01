#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define STLEN 30
//fges()琌э到gets()ㄧ计,
int main(int argc, char **argv)
{
     (void)argc;
     char Email[STLEN];
     printf("Enter your Email\n");
     fgets(Email,STLEN,stdin);
     puts(Email);//puts穦才﹃ソЮ睰传腹\n
     fputs(Email,stdout);//ぃ穦才﹃ソЮ睰传腹\n
    
	return 0;
}
