#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char **load_bmp (int *biHeight, int *biWidth, char *header, char *in_bmp) {
    FILE *file = NULL;
    file = fopen(in_bmp, "rb");
    if (file == NULL) return NULL;
    int check = 0;
    check = fread(header, 1, 54, file);
    if (check != 54) {
        fclose(file);
        return NULL;
    }

    memcpy(biWidth, header + 18, 4);
    memcpy(biHeight, header + 22, 4);

    int remainder = (4 - ((*biWidth * 3) % 4)) % 4;
    char **pix_arr = (char **) malloc(*biHeight * sizeof(char * ));
    for (int i = 0; i < *biHeight; ++i)
        pix_arr[i] = (char *) malloc(*biWidth * 3 + remainder);
    if (pix_arr == NULL) goto Error;
    check = 0;
    int amount = (*biWidth * 3);
    for (int i = 0; i < *biHeight; ++i) {
        check = fread(pix_arr[i], 1, amount + remainder, file);
        if (check != amount + remainder) goto Error;
    }
    fclose(file);
    return pix_arr;

    Error:
    fclose(file);
    for (int i = 0; i < *biHeight; ++i)
        free(pix_arr[i]);
    free(pix_arr);
    return NULL;
}

int save_bmp (char *out_bmp, char *header, char **rotate_arr, int w, int h) {
    int bfSize = w * (h * 3 + (4 - (h * 3) % 4) % 4) + 54;
    int biWidth = h;
    int biHeight = w;
    int biSizeImage = w * (h * 3 + (4 - (h * 3) % 4) % 4);

    memcpy(header + 2,&bfSize, 4);
    memcpy(header + 18,&biWidth, 4);
    memcpy(header + 22,&biHeight, 4);
    memcpy(header + 34,&biSizeImage, 4);

    int remainder = (4 - ((h * 3) % 4)) % 4;
    FILE *file = NULL;
    file = fopen(out_bmp, "wb");
    if (file == NULL) goto Error;
    int check = 0;
    check = fwrite(header, 1, 54, file);
    if (check != 54) {
        fclose(file);
        goto Error;
    }
    for (int i = 0; i < w; ++i) {
        check = 0;
        check = fwrite(rotate_arr[i], 1, (h * 3 + remainder), file);
        if (check != h * 3 + remainder) {
            fclose(file);
            goto Error;
        }
    }
    fclose(file);

    Error:
    for (int i = 0; i < w ; ++i)
        free(rotate_arr[i]);
    free(rotate_arr);
    return -1;
}

char **rotate (char **crop_arr, int w, int h) {
    int remainder = (4 - ((h * 3) % 4)) % 4;
    char **rotate_arr = (char **) malloc(w  * sizeof(char *));
    for (int i = 0; i < w; ++i)
        rotate_arr[i] = (char *) malloc(h * 3 + remainder);
    if (rotate_arr == NULL) return NULL;

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
        for (int j = h * 3; j < remainder + h * 3; ++j) {
            rotate_arr[i][j] = 0;
        }
    }
    return rotate_arr;
}

char **crop (char **pix_arr, int x, int y, int w, int h, int biHeight) {
    char **crop_arr = (char **) malloc(h * sizeof(char *));
    for (int i = 0; i < h; ++i)
        crop_arr[i] = (char *) malloc(w * 3);
    if (crop_arr == NULL) return NULL;
    
    for (int i = biHeight - h - y; i < biHeight - y; ++i) {
        for (int j = x * 3; j < (x + w) * 3; ++j) {
            crop_arr[i + y - biHeight + h][j - (x * 3)] = pix_arr[i][j];
        }
    }
    return crop_arr;
}