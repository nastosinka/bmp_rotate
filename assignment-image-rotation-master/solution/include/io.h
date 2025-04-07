#ifndef IMAGE_TRANSFORMER_IO_H
#define IMAGE_TRANSFORMER_IO_H

#include <stdbool.h>
#include <stdio.h>

bool open_file(FILE **file, const char *path,
               const char *mode);
bool close_file(FILE *file);

#endif // IMAGE_TRANSFORMER_IO_H
