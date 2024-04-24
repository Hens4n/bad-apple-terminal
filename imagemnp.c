#include "imagemnp.h"
#include "filemnp.h"

void readGenerateASCII()
{
  uint8_t *pixelValues = NULL;                                      // A Pointer that will hold pixel values from the image
  //size_t numberOfFrames = getNumberOfFrames();                    // Won't work on Windows
  size_t numberOfFrames = 6572;                                     // Just the number of grayscale frames from $home/frames/gray folder
  FILE *image;
  struct jpeg_decompress_struct imageData;                          // Allocating JPEG Decompress Object
  struct jpeg_error_mgr jErr;                                       // Error handler struct

  imageData.err = jpeg_std_error(&jErr);
  jpeg_create_decompress(&imageData);                               // Initializing JPEG Decompress Object

  for(size_t i = 0; i < numberOfFrames; i++) {
    image = openImage(i);
    jpeg_stdio_src(&imageData, image);                              // Reads compressed data

    jpeg_read_header(&imageData, TRUE);                             // Reads JPEG header and obtain image info, like Width and Height
    jpeg_start_decompress(&imageData);

    int8_t ascii[imageData.image_width+1];
    if(pixelValues == NULL) pixelValues = malloc(imageData.image_width);

    while(imageData.output_scanline < imageData.image_height) {
      jpeg_read_scanlines(&imageData, &pixelValues, 1);             // Reads 1 ROW of the decompressed data image and stores in the pointer
      getASCIILine(pixelValues, imageData.image_width, ascii);
      puts(ascii);
    }
    SLEEP();                                                      // Set the FPS
    CLEAR_SCREEN();
    jpeg_finish_decompress(&imageData);                             // Frees memory and makes the struct ready for another frame
    fclose(image);
  }
  jpeg_destroy_decompress(&imageData);
}

void generateFrames(int8_t *videoFile)                                // Generates and resizes frames from video 
{
  int8_t command[MAX_PATH];
  sprintf(command, "ffmpeg -i %s -vf scale=%d:%d %s", videoFile, TERMINAL_COLUMNS_SIZE, TERMINAL_LINES_SIZE, STORE_VFRAMES_PATH);

  system(command);
  CLEAR_SCREEN();
}

void generateGrayFrames()                                           // Convert all the frames to grayscale frames
{
  int8_t command[MAX_PATH];
  sprintf(command, "magick convert %s -colorspace Gray %s", CONVERT_FRAMES_PATH, STORE_GFRAMES_PATH);

  system(command);
}
