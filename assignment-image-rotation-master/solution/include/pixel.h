//
// Created by Osinkina Anastasiya on 30.10.2024.
//

#ifndef IMAGE_TRANSFORMER_PIXEL_H
#define IMAGE_TRANSFORMER_PIXEL_H

#include <stdint.h>

struct pixel {
    uint8_t b, g, r;
};

struct pixel init_pixel(uint8_t b,uint8_t g,uint8_t r);

#endif //IMAGE_TRANSFORMER_PIXEL_H
