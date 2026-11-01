
  #ifndef __TEST2_H
  #define __TEST2_H

#include "test1.h"
#include <stdint.h>

#define MAX_SOCKET_NUMBER 4

typedef struct{
	uint8_t family;
	uint8_t port;
	uint8_t* addr;
	socket_process socket_information;
}socket_info[MAX_SOCKET_NUMBER];
 #endif /*__TEST2_H*/
// ...