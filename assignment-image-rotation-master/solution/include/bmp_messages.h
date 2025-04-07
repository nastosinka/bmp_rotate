
#ifndef IMAGE_TRANSFORMER_BMP_MESSAGES_H
#define IMAGE_TRANSFORMER_BMP_MESSAGES_H

#include <sys/errno.h>

enum bmp_write_status {
    BMP_WRITE_OK,
    BMP_WRITE_PIXELS_ERROR,
    BMP_WRITE_HEADER_ERROR,
    BMP_WRITE_FILE_ERROR,
    BMP_WRITE_IMAGE_ERROR
};

enum bmp_read_status {
    BMP_READ_OK = 0,
    BMP_READ_OUT_OF_MEMORY = ENOMEM,
    BMP_READ_BAD_FILE,
    BMP_READ_BAD_HEADER ,
    BMP_READ_BAD_PIXELS ,
};

const char* bmp_read_status_to_string(enum bmp_read_status status);

const char* bmp_write_status_to_string(enum bmp_write_status status);


#endif //IMAGE_TRANSFORMER_BMP_MESSAGES_H
