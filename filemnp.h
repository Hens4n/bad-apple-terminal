#ifndef FILEMNP_H
#define FILEMNP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_PATH 4096                                               // File max path
#define GRAYSCALE_PATH "$home/frames/gray/"                         // Location of frames in grayscale
#define BASH_COMMAND "/bin/ls %s | wc -l"                           // Unix command to get number of files in a folder

FILE *openImage(size_t const currentImage);

size_t getNumberOfFrames();                                         // Only work on Unix

#endif 
