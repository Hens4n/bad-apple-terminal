#ifndef _IMAGEMNP_H
#define _IMAGEMNP_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "filemnp.h"
#include "ascii.h"
#include <jpeglib.h>
#include <unistd.h>

// Change $USER for yours
#define STORE_VFRAMES_PATH "/home/$USER/frames/%04d.jpg"            // Path to store frames extracted 
#define STORE_GFRAMES_PATH "/home/$USER/frames/gray/%04d.jpg"       // Path to store grayscale frames
#define CONVERT_FRAMES_PATH "/home/$USER/frames/*.jpg"              // Path to read extracted frames to conversion into Grayscale
#define CLEAR_SCREEN printf("\e[1;1H\e[2J")
#define TERMINAL_COLUMNS_SIZE 130
#define TERMINAL_LINES_SIZE 32
#define SECONDS_PER_FRAMES 33333

void readGenerateASCII();

void generateFrames(char *videoFile);

void generateGrayFrames();

#endif
