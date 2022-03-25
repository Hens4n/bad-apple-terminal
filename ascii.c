#include "ascii.h"

char getASCIIChar(u_int8_t pixelValue)
{
  if((1.0 * pixelValue / 255) >= 0.50) return '%';
  return ' ';
}

void getASCIILine(u_int8_t *pixelValue, u_int32_t bufferSize,
                   char *toASCII)
{
  for(size_t i = 0; i < bufferSize; i++)
    toASCII[i] = getASCIIChar(pixelValue[i]);
  toASCII[bufferSize] = '\0';
}
