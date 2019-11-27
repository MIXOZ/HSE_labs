#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include "bmp.h"


int main(int argc, char *argcom[]) {
    if (argc < 8) return 1;

    //обработка данных командной строки
    char *crop_rotate = argcom[1];
    char *in_bmp = argcom[2];
    char *out_bmp = argcom[3];
    int x = atoi(argcom[4]);
    int y = atoi(argcom[5]);
    int w = atoi(argcom[6]);
    int h = atoi(argcom[7]);
    if (strcmp(crop_rotate, "crop-rotate") != 0) return 2;

    //инициализация заголовков
    char header[54];

    //инициализация параметров
    int biHeigth = 0;
    int biWidth = 0;

    //чтение файла
    char **pix_arr = load_bmp (&biHeigth, &biWidth, header, in_bmp);

    //проверка корректности
    if (x + w > biWidth || y + h > biHeigth) exit(3);

    //обработка пикселей
    char **crop_arr = crop(pix_arr, x, y, w, h);
    if (crop_arr == NULL) return 6;
    if (pix_arr == NULL) return 6;
    char **final_arr = rotate(crop_arr, w, h);
    if (crop_arr == NULL) return 6;
    if (final_arr == NULL) return 6;

    //запись
    save_bmp (out_bmp, header, final_arr, w, h);
    
    for (int i = 0; i < biHeigth; ++i)
        free(pix_arr[i]);
    free(pix_arr);

    for (int i = 0; i < h; ++i)
        free(crop_arr[i]);
    free(crop_arr);

    for (int i = 0; i < w ; ++i)
        free(final_arr[i]);
    free(final_arr);
    return 0;
}