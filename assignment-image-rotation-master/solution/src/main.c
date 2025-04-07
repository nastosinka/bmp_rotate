#include "bmp_header.h"
#include "bmp_messages.h"
#include "bmp_reader.h"
#include "bmp_transformer.h"
#include "bmp_writer.h"
#include "image.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    (void)argc;

    FILE *source_file = NULL;
    const char *path = argv[1];
    const char *output_filename = argv[2];
    const bool status = open_file(&source_file, path, "rb");

    if (status == false) {
        const int current_error = errno; // exit code
        fprintf(stderr, "Ошибка открытия файла: `%s` по причине `%s`", path,
                strerror(current_error));
        return current_error;
    }

    struct image image;
    const enum bmp_read_status read_result = bmp_read_image(source_file, &image);

    if (close_file(source_file) == false) {
        fprintf(stderr, "Ошибка закрытия файла: `%s`", path);
    }

    if (read_result != BMP_READ_OK) {
        fprintf(stderr, "%s\n", bmp_read_status_to_string(read_result));
        return read_result;
    }

    const struct image new_image = bmp_transform(image);
    const struct bmp_header header = bmp_header_creator(&new_image);

    FILE *output_file = NULL;

    if (open_file(&output_file, output_filename, "wb") == false) {
        free(image.data);
        free(new_image.data);

        const int current_error1 = errno;
        fprintf(stderr, "Ошибка записи: `%s` по причине `%s`", output_filename,
                strerror(current_error1));
        return current_error1;
    }

    const enum bmp_write_status write_result =
            bmp_write_image(output_file, &header, &new_image);

    if (write_result != BMP_WRITE_OK) {
        free(image.data);
        free(new_image.data);
        fprintf(stderr, "%s\n", bmp_write_status_to_string(write_result));
        return write_result;
    }

    if (close_file(output_file) == false) {
        fprintf(stderr, "Ошибка закрытия открытого файла: `%s`", path);
    }

    free(image.data);
    free(new_image.data);

    return 0;
}

