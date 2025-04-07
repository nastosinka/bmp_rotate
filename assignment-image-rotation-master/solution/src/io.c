//
// Created by Osinkina Anastasiya on 30.10.2024.
//
#include "io.h"
#include <stdio.h>
#include <stdlib.h>

bool open_file(FILE **file, const char *path, const char *mode) {
  *file = fopen(path, mode);
  return *file != NULL;
} // файл ресурсов путь и режим открытия

bool close_file(FILE *file) { return fclose(file) == 0; }
