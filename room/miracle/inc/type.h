

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum RESULT {
	FAILED = 0,
	OK
};

typedef unsigned int   ui32;
typedef unsigned char  ub8;

#define LOGI( fmt, ... ) printf( "I/%s, %s:"#fmt, __FILE__, __LINE__, ##__VA_ARGS__ );
#define LOGW( fmt, ... ) printf( "W/%s, %s:"#fmt, __FILE__, __LINE__, ##__VA_ARGS__ );
#define LOGE( fmt, ... ) printf( "E/%s, %s:"#fmt, __FILE__, __LINE__, ##__VA_ARGS__ );
#define PRINT( fmt, ... ) printf( ">>> #fmt <<<", ##__VA_ARGS__ );
