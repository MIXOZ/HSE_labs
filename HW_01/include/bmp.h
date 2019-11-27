#ifndef MAIN_C_BMP_H
#define MAIN_C_BMP_H


char **load_bmp (int *biHeigth, int *biWidth, char *header, char *in_bmp);
void save_bmp (char *out_bmp, char *header, char **final_arr, int w, int h);
char **rotate (char **input_bmp, int x, int y);
char **crop (char **input_bmp, int x, int y, int w, int h);

#endif //MAIN_C_BMP_H
