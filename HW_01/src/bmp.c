#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char **load_bmp (int *biHeigth, int *biWidth, char *header, char *in_bmp) {
    FILE *file = NULL;
    file = fopen(in_bmp, "rb");
    if (file == NULL) exit(4);
    int check = 0;
    check = fread(header, 1, 54, file);
    if (check != 54) exit(5);

    memcpy(biWidth, header + 18, 4);
    memcpy(biHeigth, header + 22, 4);

    int ostatok = (4 - ((*biWidth * 3) % 4)) % 4;
    char **pix_arr = (char **) malloc(*biHeigth * sizeof(char * ));
    for (int i = 0; i < *biHeigth; ++i)
        pix_arr[i] = (char *) malloc(*biWidth * 3 + ostatok);

    check = 0;
    int amount = (*biWidth * 3);
    for (int i = 0; i < *biHeigth; ++i) {
        check = fread(pix_arr[i], 1, amount + ostatok, file);
        if (check != amount + ostatok) exit(5);
    }
    fclose(file);
    return pix_arr;
}

void save_bmp (char *out_bmp, char *header, char **rotate_arr, int w, int h) {
    int bfSize = w * (h * 3 + (4 - (h * 3) % 4) % 4) + 54;
    int biWidth = h;
    int biHeigth = w;
    int biSizeImage = w * (h * 3 + (4 - (h * 3) % 4) % 4);

    memcpy(header + 2,&bfSize, 4);
    memcpy(header + 18,&biWidth, 4);
    memcpy(header + 22,&biHeigth, 4);
    memcpy(header + 34,&biSizeImage, 4);

    int ostatok = (4 - ((h * 3) % 4)) % 4;
    FILE *file = NULL;
    file = fopen(out_bmp, "wb");
    if (file == NULL) exit(4);
    int check = 0;
    check = fwrite(header, 1, 54, file);
    if (check != 54) exit(5);
    for (int i = 0; i < w; ++i) {
        fwrite(rotate_arr[i], 1, (h * 3 + ostatok), file);
    }
    fclose(file);
}

char **rotate (char **crop_arr, int w, int h) {
    int ostatok = (4 - ((h * 3) % 4)) % 4;
    char **rotate_arr = (char **) malloc(w  * sizeof(char *));
    for (int i = 0; i < w; ++i)
        rotate_arr[i] = (char *) malloc(h * 3 + ostatok);

    if (rotate_arr == NULL) exit(6);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w * 3; ++j) {
            int k = 3 - j % 3;
            int t = 3 * (h - i) - k;
            k = -2;
            if (t % 3 == 1) k = 0;
            else if (t % 3 == 0) k = 2;
            rotate_arr[w - j / 3 - 1][3 * h - t - k - 1] = crop_arr[i][j];
        }
    }
    for (int i = 0; i < w; ++i) {
        for (int j = h * 3; j < ostatok; ++j) {
            rotate_arr[i][j] = 0;
        }
    }
    return rotate_arr;
}

char **crop (char **input_bmp, int x, int y, int w, int h) {
    char **crop_arr = (char **) malloc(h * sizeof(char *));
    for (int i = 0; i < h; ++i)
        crop_arr[i] = (char *) malloc(w * 3);
    if (crop_arr == NULL) exit(6);
    for (int i = y; i < y + h; ++i)
        for (int j = x * 3; j < (x + w) * 3; ++j)
            crop_arr[i - y][j - (x * 3)] = input_bmp[i][j];
        return crop_arr;
}