#ifndef IMAGEMNP_H
#define IMAGEMNP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "filemnp.h"
#include "ascii.h"
#include <jpeglib.h>
#ifdef _WIN32
#include <windows.h>
#define SLEEP() Sleep(21);
#endif
#ifdef __linux__
#include <unistd.h>
#define SLEEP() usleep(21000)
#endif

// Change $USER for yours
#define STORE_VFRAMES_PATH "$home/frames/%04d.jpg"            // Path to store frames extracted 
#define STORE_GFRAMES_PATH "$home/frames/gray/%04d.jpg"       // Path to store grayscale frames
#define CONVERT_FRAMES_PATH "$home/frames/*.jpg"              // Path to read extracted frames to conversion into Grayscale
#define CLEAR_SCREEN() printf("\e[1;1H\e[2J")
#define TERMINAL_COLUMNS_SIZE 209
#define TERMINAL_LINES_SIZE 52

void readGenerateASCII();

void generateFrames(int8_t *videoFile);

void generateGrayFrames();

#endif
