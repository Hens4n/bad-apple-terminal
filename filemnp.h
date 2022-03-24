#ifndef _FILEMNP_H
#define _FILEMNP_H

#ifndef _STDIO_H
#include <stdio.h>
#endif
#ifndef _STDLIB_H
#include <stdlib.h>
#endif 

#define MAX_PATH 4096
#define GRAYSCALE_PATH "~/frames/gray"
#define BASH_COMMAND "/bin/ls ~/frames/gray | wc -l"

FILE *openImage(size_t const currentImage);

size_t getFramesQuantity();

#endif 
