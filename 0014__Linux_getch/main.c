#include <stdio.h>
#include <termio.h>

int sh_getch( void ) 
{
     int cr;
     struct termios nts, ots;

    if (tcgetattr( 0 , &ots) < 0 ) // 得到當前終端(0表示標準輸入)的設置
        return EOF;

    nts = ots;
    cfmakeraw( &nts); // 設置終端為Raw原始模式，該模式下所有的輸入數據以字節為單位被處理
    if (tcsetattr( 0 , TCSANOW, &nts) < 0 ) // 設置上更改之後的設置
        return EOF;

    cr = getchar();
     if (tcsetattr( 0 , TCSANOW, &ots) < 0 ) // 設置還原成老的模式
        return EOF;

    return cr;
}
int main(int argc, char **argv)
{
	  int ch;
    
    printf( " 請按任意鍵繼續. . . " );
    ch = sh_getch();
    printf( " %d => %c\n " , ch, ch);
    
    ch = sh_getch();
    printf( " %d => %c\n " , ch, ch);
	return 0;
}
