
#include "pixel.h"
#include <stdint.h>


struct pixel init_pixel(uint8_t b,uint8_t g,uint8_t r) {
    return (struct pixel) {
            .r = r,
            .b = b,
            .g = g
    };
}

