#include "ascii.h"

char const asciiSymbol[16] = {
    ' ', ' ', ' ', ' ',
    '-', '*', '~', '+',
    '1', ';', 'O', 'o',
    '&', '%', '%', '%'
};

void getASCIILine(uint8_t *pixelValue, size_t bufferSize,
                  int8_t *toASCII)
{
  for(size_t i = 0; i < bufferSize; i++)
    toASCII[i] = asciiSymbol[pixelValue[i]/17];
  toASCII[bufferSize] = '\0';
}
