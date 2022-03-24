#include "imagemnp.h"
#include "filemnp.h"

void readGenerateASCII()
{
  u_int8_t *pixelValues = NULL;                                     // A Pointer that will hold pixel values from the image
  size_t numberOfFrames = 1;                                        // Will be returned by a function (not yet written)
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
