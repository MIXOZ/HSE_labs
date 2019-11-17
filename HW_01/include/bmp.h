#ifndef MAIN_C_BMP_H
#define MAIN_C_BMP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>


void load_bmp (uint8_t **piks_arr, FILE *f_in_bmp, int biHeigth, int biWidth);
void save_bmp (char *out_bmp, uint8_t *header, uint8_t **final_arr, int w, int h);
void rotate (uint8_t **input_bmp, uint8_t **output_bmp, int x, int y);
void crop (uint8_t **input_bmp, uint8_t **output_bmp, int x, int y, int w, int h);

#endif //MAIN_C_BMP_H
