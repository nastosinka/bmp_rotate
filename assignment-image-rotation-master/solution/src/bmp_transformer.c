

#include "bmp_transformer.h"
#include "image.h"


struct image bmp_transform(const struct image image) {
  struct image new_image = init_image(image.height, image.width);

  //f(x,y) = (n-x-1, y)

  for (int i=0; i < new_image.width; i++) {
      for (int j=0; j < new_image.height; j++) {
          new_image.data[(j) * new_image.width + new_image.width-i-1] =image.data[i * image.width + j];


      }
  }

  return new_image;
}
