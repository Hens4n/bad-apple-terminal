#include "imagemnp.h"
#include "filemnp.h"

void readGenerateASCII()
{
  u_int8_t *pixelValues = NULL;                                     // A Pointer that will hold pixel values from the image
  size_t numberOfFrames = getFramesQuantity();                       
  FILE *image;
  struct jpeg_decompress_struct imageData;                          // Allocating JPEG Decompress Object
//struct jpeg_error_mgr jErr;                                       // Error handler struct

  jpeg_create_decompress(&imageData);                               // Initializing JPEG Decompress Object

  for(size_t i = 0; i < numberOfFrames; i++) {
    image = openImage(i);
    jpeg_stdio_src(&imageData, image);                              // Reads compressed data

    jpeg_read_header(&imageData, TRUE);                             // Reads JPEG header and obtain image info
    jpeg_start_decompress(&imageData);

    if(pixelValues == NULL) pixelValues = malloc(imageData.image_width);

    while(imageData.output_scanline < imageData.image_height) {
      jpeg_read_scanlines(&imageData, &pixelValues, 1);             // Reads 1 ROW of the decompressed data image and stores in the pointer
      // Some function here to deal with convertion
      // to ASCII and to save it in a txt file
    }
    jpeg_finish_decompress(&imageData);
    fclose(image);
  }
  jpeg_destroy_decompress(&imageData);
}

void generateFrames(char *videoFile)                                // Generates and resizes frames from video 
{
  char *program = "ffmpeg";
  char *args[] = {program, "-i", videoFile, "-vf", "scale=80:-1", STORE_VFRAMES_PATH, NULL};

  execvp(program, args);                                            // Check execvp from unistd.h 
}

void generateGrayFrames()                                           // Convert all the frames to grayscale frames
{
  char *program = "convert";
  char *args[] = {program, CONVERT_FRAMES_PATH, "-colorspace", "Gray", STORE_GFRAMES_PATH, NULL};

  execvp(program, args);                                            // Check execvp from unistd.h
}
