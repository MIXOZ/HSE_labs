#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

void load_bmp (uint8_t **piks_arr, FILE *f_in_bmp, int biHeigth, int biWidth) {
    int check = 0;

    uint8_t end_pix_read[4];

    int amount = (biWidth * 3);
    for (int i = 0; i < biHeigth; ++i) {
        check = fread(piks_arr[i], 1, amount, f_in_bmp);
        fread(end_pix_read, 1, (biWidth * 3) % 4, f_in_bmp);
        assert(check == amount);
    }
}

void save_bmp (char *out_bmp, uint8_t *header, uint8_t **final_arr, int w, int h) {
    FILE *f_out_bmp = NULL;
    f_out_bmp = fopen(out_bmp, "ab");
    assert(f_out_bmp != NULL);
    int check = 0;
    check = fwrite(header, 1, 54, f_out_bmp);
    assert(check != 0);

    int amount = (h * 3) % 4;

    uint8_t end_pix_write[amount];
    for (int i = 0; i < w; ++i) {
        fwrite(final_arr[i], 1, (h * 3), f_out_bmp);
        fwrite(end_pix_write, 1, amount, f_out_bmp);
    }
    fclose(f_out_bmp);
}

void rotate (uint8_t **input_bmp, uint8_t **output_bmp, int x, int y) {
    for (int i = 0; i < y; ++i)
        for (int j = 0; j < x * 3; ++j){
            //int k = 3 -;
            int k = j % 3;
            if (k == 0) k = 3;
            output_bmp[(x * 3 - j - 1) / 3][k + 3 * i] = input_bmp[i][j];
        }
}

void crop (uint8_t **input_bmp, uint8_t **output_bmp, int x, int y, int w, int h) {
    for (int i = y; i < y + h; ++i)
        for (int j = x * 3; j < (x + w) * 3; ++j)
            output_bmp[i - y][j - (x * 3)] = input_bmp[i][j];
}