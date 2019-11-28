#ifndef MAIN_C_BMP_H
#define MAIN_C_BMP_H


char **load_bmp (int *biHeight, int *biWidth, char *header, char *in_bmp);
int save_bmp (char *out_bmp, char *header, char **rotate_arr, int w, int h);
char **rotate (char **crop_arr, int w, int h);
char **crop (char **pix_arr, int x, int y, int w, int h, int biHeight);

#endif //MAIN_C_BMP_H
