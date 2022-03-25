#ifndef _FILEMNP_H
#define _FILEMNP_H

#ifndef _STDIO_H
#include <stdio.h>
#endif
#ifndef _STDLIB_H
#include <stdlib.h>
#endif 

#define MAX_PATH 4096                                               // File max path
#define GRAYSCALE_PATH "/home/$USER/frames/gray/"                   // Location of frames in grayscale. Change $USER for yours
#define BASH_COMMAND "/bin/ls %s | wc -l"                           // Unix command to get number of files in a folder

FILE *openImage(size_t const currentImage);

size_t getNumberOfFrames();

#endif 
