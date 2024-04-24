#include "filemnp.h"

FILE *openImage(size_t const currentImage)
{
  int8_t fileName[MAX_PATH];                                                // Stores the Path where the frames are
  FILE *image;

  sprintf(fileName, "%s%04zu.jpg", GRAYSCALE_PATH, currentImage);          // %04zu because I have 10⁴ frames
  if((image = fopen(fileName, "rb")) == NULL) {
    printf("Image could not be opened.\n");
    exit(EXIT_FAILURE);
  }

  return image;
}

size_t getNumberOfFrames()
{
  FILE *rStdout;                                                          // Gets stdout into rStdout 
  int8_t bashCommand[MAX_PATH];
  int8_t framesQuantity[10];                                                // Stores 10⁹ number of frames
  size_t aux;

  sprintf(bashCommand, BASH_COMMAND, GRAYSCALE_PATH);

  if((rStdout = popen(bashCommand, "r")) == NULL) {                      // popen to read stdout in the file
    printf("There was an error reading stdout.\n");
    exit(EXIT_FAILURE);
  }

  fgets(framesQuantity, sizeof framesQuantity, rStdout);
  sscanf(framesQuantity, "%zu", &aux);

  return aux;
}
