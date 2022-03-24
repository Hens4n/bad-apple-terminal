#ifndef _IMAGEMNP_H
#define _IMAGEMNP_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "filemnp.h"
#include <jpeglib.h>
#include <unistd.h>

// Change $USER for yours
#define STORE_VFRAMES_PATH "/home/$USER/frames/%04d.jpg"            // Path to store frames extracted 
#define STORE_GFRAMES_PATH "/home/$USER/frames/gray/%04d.jpg"       // Path to store grayscale frames
#define CONVERT_FRAMES_PATH "/home/$USER/frames/*.jpg"              // Path to read extracted frames to conversion

void readGenerateASCII();

void generateFrames(char *videoFile);

void generateGrayFrames();

#endif
