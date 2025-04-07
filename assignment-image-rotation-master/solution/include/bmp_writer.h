//
// Created by Osinkina Anastasiya on 30.10.2024.
//

#ifndef IMAGE_TRANSFORMER_BMP_WRITER_H
#define IMAGE_TRANSFORMER_BMP_WRITER_H
#include "bmp_header.h"
#include "bmp_messages.h"
#include "image.h"

enum bmp_write_status bmp_write_image(FILE *bmp_file,
                                      const struct bmp_header *header,
                                      const struct image *image);

#endif // IMAGE_TRANSFORMER_BMP_WRITER_H
