//
// Created by Osinkina Anastasiya on 30.10.2024.
//

#ifndef IMAGE_TRANSFORMER_BMP_READER_H
#define IMAGE_TRANSFORMER_BMP_READER_H
#include "bmp_messages.h"
#include "image.h"
#include <errno.h>
#include <stdio.h>

enum bmp_read_status bmp_read_image(FILE *bmp_file, struct image *image);

#endif // IMAGE_TRANSFORMER_BMP_READER_H
