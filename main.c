#include "imagemnp.h"
#include "filemnp.h"

int main(int argc, char **argv)
{
  if(argc != 2) {
    printf("The Parameter is incorrect.\n");
    exit(EXIT_FAILURE);
  }

  generateFrames(argv[1]);                                          // Generates frames from source video  
  generateGrayFrames();                                             // Generates grayscale frames for each frame
  readGenerateASCII();                                              // Handles ASCII creation

  return EXIT_SUCCESS;
}
