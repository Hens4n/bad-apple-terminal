#ifndef _FILEMNP_H
#include "filemnp.h"
#endif

FILE *openImage(size_t const currentImage)
{
  char fileName[MAX_PATH];                                                // Stores the Path where the frames are
  FILE *image;

  sprintf(fileName, "%s%04zu.jpg", GRAYSCALE_PATH, currentImage);          // %04zu because I have 10⁴ frames
  if((image = fopen(fileName, "rb")) == NULL) {
    printf("Image could not be opened.\n");
    exit(EXIT_FAILURE);
  }

  return image;
}

size_t getFramesQuantity()
{
  FILE *rStdout;
  char framesQuantity[10];
  size_t aux;

  if((rStdout = popen(BASH_COMMAND, "r")) == NULL) {
    printf("There was an error reading stdout.\n");
    exit(EXIT_FAILURE);
  }

  fgets(framesQuantity, sizeof framesQuantity, rStdout);
  sscanf(framesQuantity, "%zu", &aux);

  return aux;
}
