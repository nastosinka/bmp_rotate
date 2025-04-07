//
// Created by Osinkina Anastasiya on 07.11.2024.
//


#include "bmp_messages.h"

static const char *bmp_read_messages[] = {
        [BMP_READ_OK] = "BMP файл прочитан.",
        [BMP_READ_OUT_OF_MEMORY] = "Ошибка: переполнена память.",
        [BMP_READ_BAD_FILE] = "Ошибка: недопустимый формат файла",
        [BMP_READ_BAD_HEADER] = "Ошибка: недопустимый формат заголовка",
        [BMP_READ_BAD_PIXELS] = "Ошибка записи: недопустимый формат пикселей."
};
static const char *bmp_write_messages[] = {
        [BMP_WRITE_OK] = "Запись прошла успешно.",
        [BMP_WRITE_PIXELS_ERROR] = "Ошибка записи: недопустимый формат пикселей.",
        [BMP_WRITE_HEADER_ERROR] = "Ошибка записи: недопустимый формат заголовка.",
        [BMP_WRITE_IMAGE_ERROR] = "Ошибка записи: отсутствуют данные для записи.",
        [BMP_WRITE_FILE_ERROR] = "Ошибка записи: недопустимый формат файла."
};

const char* bmp_read_status_to_string(enum bmp_read_status status) {
    if (status >= sizeof(bmp_read_messages)/sizeof(const char *)) {
        return "Ошибка.";
    }
    return bmp_read_messages[status];
}

const char* bmp_write_status_to_string(enum bmp_write_status status) {
    if (status >= sizeof(bmp_write_messages)/sizeof(const char *)) {
        return "Ошибка.";
    }
    return bmp_write_messages[status];
}
