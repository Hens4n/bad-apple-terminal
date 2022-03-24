#ifndef _FILEMNP_H
#define _FILEMNP_H

#ifndef _STDIO_H
#include <stdio.h>
#endif
#ifndef _STDLIB_H
#include <stdlib.h>
#endif 

#define PATH_MAX 260
#define PATH_DEFAULT "~/frames/"
#define PATH_GRAYSCALE "~/frames/gray"

FILE *openImage(size_t const currentImage);

#endif 
