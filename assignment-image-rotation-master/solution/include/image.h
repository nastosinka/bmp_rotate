#ifndef IMAGE_TRANSFORMER_IMAGE_H
#define IMAGE_TRANSFORMER_IMAGE_H

#include "pixel.h"
#include <stdint.h>

struct image {
  uint64_t width, height;
  struct pixel *data;
};

struct image init_image(uint64_t w, uint64_t h);

#endif // IMAGE_TRANSFORMER_IMAGE_H
