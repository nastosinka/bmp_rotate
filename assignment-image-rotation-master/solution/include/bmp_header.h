//
// Created by Osinkina Anastasiya on 30.10.2024.
//

#ifndef IMAGE_TRANSFORMER_BMP_H
#define IMAGE_TRANSFORMER_BMP_H


#include "bmp_messages.h"
#include "image.h"
#include <stdint.h>
#include <stdio.h>

struct __attribute__((packed)) bmp_header {
  uint16_t bfType;
  uint32_t bfileSize;
  uint32_t bfReserved;
  uint32_t bOffBits;
  uint32_t biSize;
  uint32_t biWidth;
  uint32_t biHeight;
  uint16_t biPlanes;
  uint16_t biBitCount;
  uint32_t biCompression;
  uint32_t biSizeImage;
  uint32_t biXPelsPerMeter;
  uint32_t biYPelsPerMeter;
  uint32_t biClrUsed;
  uint32_t biClrImportant;
};

enum bmp_read_status bmp_read_header(FILE *bmp_file, struct bmp_header *header);

struct bmp_header bmp_header_creator(const struct image *image);

#endif // IMAGE_TRANSFORMER_BMP_H
// шеуьы_цкшееут - запись мусор ityms_written
