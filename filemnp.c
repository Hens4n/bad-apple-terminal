#ifndef _FILEMNP_H
#include "filemnp.h"
#endif

FILE *openImage(size_t const currentImage)
{
  char fileName[PATH_MAX] = "~/frames/";                // Path where the frames are
  FILE *image;

  sprintf(fileName, "%04zu.jpg", currentImage);          // %04zu because I have 10⁴ frames
  if((image = fopen(fileName, "rb")) == NULL) {
    printf("Image could not be opened.\n");
    exit(EXIT_FAILURE);
  }

  return image;
}
