#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include "bmp.h"

int get_int (uint8_t *header, int size) {
    int value = 0;
    int exp = 1;
    for (int i = 0; i < size; ++i) {
        value += header[i] * exp;
        exp*= 256;
    }
    return value;
}

void print_int (uint8_t *header, int size, int value) {
    for (uint8_t i = 0; i < size; ++i) {
        *(header + i) = (value >> (8 * i) )& 255;
    }
}


int main(int argc, char *argcom[]) {
    //obrabotka dannuh komandnoy stroki
    char *crop_rotate = argcom[1];
    char *in_bmp = argcom[2];
    char *out_bmp = argcom[3];
    int x = atoi(argcom[4]);
    int y = atoi(argcom[5]);
    int w = atoi(argcom[6]);
    int h = atoi(argcom[7]);

    (void)argc;
    (void)crop_rotate;
    //if (crop_rotate != "crop_rotate") return 0;

    //inicializaciya zagolovkov
    uint8_t header[54];
    FILE *f_in_bmp = NULL;
    f_in_bmp = fopen(in_bmp, "rb");
    assert(f_in_bmp != NULL);
    int check = 0;
    check = fread(header, 1, 54, f_in_bmp);
    assert(check != 0);

    //inicializaciya parametrov
    int bfSize = get_int(header + 2, 4);//Razmer faila
    //bfOffbits = get_int(header + 10, 4);
    int biWidth = get_int(header + 18, 4);//shirina v pikseliah
    int biHeigth = get_int(header + 22, 4);//visota v pikseliah


    //chtenie pikseley
    uint8_t **piks_arr = (uint8_t **) malloc(biHeigth * sizeof(uint8_t * ));
    for (int i = 0; i < biHeigth; ++i)
        piks_arr[i] = (uint8_t *) malloc(biWidth * 3);
    load_bmp (piks_arr, f_in_bmp, biHeigth, biWidth);
    fclose(f_in_bmp);

    //obrabotka pikseley
    uint8_t **crop_arr = (uint8_t **) malloc(h * sizeof(uint8_t * ));
    for (int i = 0; i < h; ++i)
        crop_arr[i] = (uint8_t *) malloc(w * 3);
    assert(crop_arr != NULL);
    crop(piks_arr, crop_arr, x, y, w, h);

    assert(crop_arr != NULL);
    assert(piks_arr != NULL);

    uint8_t **final_arr = (uint8_t **) malloc(w * sizeof(uint8_t * ));
    for (int i = 0; i < w; ++i)
        final_arr[i] = (uint8_t *) malloc(h * 3);

    assert(final_arr != NULL);
    rotate(crop_arr, final_arr, w, h);
    assert(crop_arr != NULL);
    assert(final_arr != NULL);

    //zapis
    bfSize = w * h * 3 + 54;//Razmer faila
    biWidth = h;//shirina v pikseliah
    biHeigth = w;//visota v pikseliah
    print_int(header + 2, 4, bfSize);//Razmer faila
    print_int(header + 18, 4, biWidth);//shirina v pikseliah
    print_int(header + 22, 4, biHeigth);//visota v pikseliah

    save_bmp (out_bmp, header, final_arr, w, h);

    for (int i = 0; i < biHeigth; ++i)
        free(piks_arr[i]);
    free(piks_arr);

    for (int i = 0; i < h; ++i)
        free(crop_arr[i]);
    free(crop_arr);

    for (int i = 0; i < w; ++i)
        free(final_arr[i]);
    free(final_arr);
    return 0;
}