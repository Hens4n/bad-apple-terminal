#include "imagemnp.h"
#include "filemnp.h"


int main(int argc, char **argv)
{
  if(argc != 2) {
    printf("The Parameter is incorrect.\n");
    exit(EXIT_FAILURE);
  }

  generateFrames(argv[1]);                                          // Generate frames from source video  
  generateGrayFrames();                                             // Generate grayscale frames for each frame

  return EXIT_SUCCESS;
}
