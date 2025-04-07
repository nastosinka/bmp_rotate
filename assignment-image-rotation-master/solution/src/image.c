#include "image.h"
#include "pixel.h"
#include <stdint.h>
#include <stdlib.h>

struct image init_image(uint64_t w, uint64_t h) {
  return (struct image){
      .data = calloc(w * h, sizeof(struct pixel)),
      .width = w,
      .height = h,
  };
}
