#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include "bmp.h"


int main(int argc, char *argcom[]) {
    if (argc != 8) return -1;

    //обработка данных командной строки
    char *crop_rotate = argcom[1];
    char *in_bmp = argcom[2];
    char *out_bmp = argcom[3];
    int x = atoi(argcom[4]);
    int y = atoi(argcom[5]);
    int w = atoi(argcom[6]);
    int h = atoi(argcom[7]);
    if (strcmp(crop_rotate, "crop-rotate") != 0) return -1;

    //инициализация заголовков
    char header[54];

    //инициализация параметров
    int biHeight = 0;
    int biWidth = 0;

    //чтение файла
    char **pix_arr = load_bmp (&biHeight, &biWidth, header, in_bmp);
    if (pix_arr == NULL) return -1;

    //проверка корректности
    if (x + w > biWidth || y + h > biHeight) {
        for (int i = 0; i < biHeight; ++i)
            free(pix_arr[i]);
        free(pix_arr);
        return -1;
    }

    //обработка пикселей
    char **crop_arr = crop(pix_arr, x, y, w, h, biHeight);

    for (int i = 0; i < biHeight; ++i)
        free(pix_arr[i]);
    free(pix_arr);

    if (crop_arr == NULL) return -1;

    char **rotate_arr = rotate(crop_arr, w, h);

    for (int i = 0; i < h; ++i)
        free(crop_arr[i]);
    free(crop_arr);

    if (rotate_arr == NULL) return -1;

    //запись
    int check = 0;
    check = save_bmp (out_bmp, header, rotate_arr, w, h);
    if (check == -1) return -1;
    
    for (int i = 0; i < w ; ++i)
        free(rotate_arr[i]);
    free(rotate_arr);
    
    return 0;
}