
#include "bmp_reader.h"
#include "bmp_header.h"
#include "bmp_messages.h"
#include "image.h"
#include "pixel.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIGNATURE 0x4d42

enum bmp_read_status bmp_read_image(FILE *bmp_file, struct image *image) {
  if (fseek(bmp_file, 0, SEEK_SET) == -1) { // это просто 0 пиксель файла
    return BMP_READ_BAD_FILE;
  }

  struct bmp_header header;
  if (fread(&header, sizeof(struct bmp_header), 1, bmp_file) != 1) {
    return BMP_READ_BAD_HEADER;
  }

  if (header.bfType != BMP_HEADER_SIGNATURE) {
    return BMP_READ_BAD_HEADER;
  }

  if (header.biBitCount != 8 * sizeof(struct pixel)) {
    return BMP_READ_BAD_HEADER;
  }

  if (header.biCompression != 0) {
    return BMP_READ_BAD_HEADER;
  }

  if (fseek(bmp_file, header.bOffBits, SEEK_SET) ==
      -1) { // здесь начинаются пиксели
    return BMP_READ_BAD_PIXELS;
  }

  *image = init_image(header.biWidth, header.biHeight);

  if (image->data == NULL) {
    return BMP_READ_OUT_OF_MEMORY;
  }

  const uint32_t bmp_padding_size = 4;
  const uint32_t size_of_line_bytes = header.biWidth * sizeof(struct pixel);
  const uint32_t size_of_line_in_bmp_in_bytes =
      size_of_line_bytes +
      (bmp_padding_size - size_of_line_bytes % bmp_padding_size) %
          bmp_padding_size;

  const uint32_t padding = size_of_line_in_bmp_in_bytes - size_of_line_bytes;

  for (uint32_t y = 0; y < image->height; ++y) {
    struct pixel *current_line =
        image->data + y * image->width; // собираем текущую линию

    if (fread(current_line, size_of_line_bytes, 1, bmp_file) != 1) {
      free(image->data);
      image->data = NULL;
      return BMP_READ_BAD_PIXELS;
    }

    if (fseek(bmp_file, padding, SEEK_CUR) == -1) {
      free(image->data);
      image->data = NULL;
      return BMP_READ_BAD_FILE;
    }
  }

  return BMP_READ_OK;
}
