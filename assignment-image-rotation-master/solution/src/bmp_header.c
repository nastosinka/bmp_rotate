//
// Created by Osinkina Anastasiya on 08.11.2024.
//

#include "bmp_header.h"
#include "bmp_messages.h"
#include "image.h"
#include "pixel.h"
#include <stdint.h>
#include <stdio.h>

struct bmp_header bmp_header_creator(const struct image *image) {
  const uint32_t size = image->width * image->height;
  return (struct bmp_header){.bfType = 0x4D42,
                             .bfileSize = sizeof(struct bmp_header) + size,
                             .bfReserved = 0,
                             .bOffBits = sizeof(struct bmp_header),
                             .biSize = 40,
                             .biWidth = image->width,
                             .biHeight = image->height,
                             .biPlanes = 1,
                             .biBitCount = sizeof(struct pixel) * 8,
                             .biCompression = 0,
                             .biSizeImage = size,
                             .biXPelsPerMeter = 0,
                             .biYPelsPerMeter = 0,
                             .biClrUsed = 0,
                             .biClrImportant = 0};
}

enum bmp_read_status bmp_read_header(FILE *bmp_file,
                                     struct bmp_header *header) {
  const unsigned long items_read =
      fread(header, sizeof(struct bmp_header), 1, bmp_file);
  if (items_read != 1) {
    return BMP_READ_BAD_HEADER;
  }
  return BMP_READ_OK;
}
