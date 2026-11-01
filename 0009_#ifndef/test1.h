/*test1.h*/

   #ifndef __TEST1_H
   #define __TEST1_H

#define SerialName      "my_test_0001\n"
#define SW_version          "V.1.3.0\n"
#define FW_version          "V.1.3.0\n"

typedef enum
{
    socket_init = 0,
    socket_connecting,
    socket_connected,
	socket_close
}socket_process;

 #endif /*__TEST1_H*/