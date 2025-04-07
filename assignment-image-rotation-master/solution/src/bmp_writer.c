//
// Created by Osinkina Anastasiya on 06.11.2024.
//

#include "bmp_writer.h"
#include "bmp_header.h"
#include "bmp_messages.h"
#include "image.h"
#include "pixel.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

enum bmp_write_status bmp_write_image(FILE *bmp_file,
                                      const struct bmp_header *header,
                                      const struct image *image) {
  // проверяем не null ли
  if (image == NULL) {
    return BMP_WRITE_IMAGE_ERROR;
  }

  unsigned long written_file =
      fwrite(header, sizeof(struct bmp_header), 1, bmp_file);
  if (written_file != 1) {
    return BMP_WRITE_FILE_ERROR;
  }

  const uint32_t bmp_padding_size = 4;
  const uint32_t line_size = header->biWidth * sizeof(struct pixel);
  const uint32_t padding = (bmp_padding_size- (line_size % bmp_padding_size)) % bmp_padding_size;

  for (uint32_t i = 0; i != header->biHeight; i++) {
    written_file =
        fwrite(image->data + i * header->biWidth, line_size, 1, bmp_file);

    if (written_file != 1) {
      return BMP_WRITE_FILE_ERROR;
    }

    written_file = fwrite(&padding, padding, 1, bmp_file);

    if (written_file != 1) {
      return BMP_WRITE_FILE_ERROR;
    }
  }

  return BMP_WRITE_OK;
}
