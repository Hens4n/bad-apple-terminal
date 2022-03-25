#ifndef _ASCII_H
#define _ASCII_H

#ifndef _STDLIB_H
#include <stdlib.h>
#endif
#ifndef _STDIO_H
#include <stdio.h>
#endif

char getASCIIChar(u_int8_t pixelValue);

void getASCIILine(u_int8_t *pixelValue, u_int32_t bufferSize,
                   char *toASCII);

#endif
