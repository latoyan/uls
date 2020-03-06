#include "uls.h"

void mx_print_names2(t_li **names, int maxlen, int wincol, st_fl *fl) {
    int rows;
    int cols = (wincol / maxlen) != 0 ? wincol / maxlen : 1;
    int num = 0;

    for(;names[num]; num++) {
    }
    if (maxlen * cols > wincol && cols != 1)
        cols--;
    if (num * maxlen > wincol) {
        rows = num / cols;
        if (rows == 0 || num % cols != 0)
            rows += 1;
        if (fl->x == 0)
            mx_printcols_c(names, rows, num, maxlen);
        else
            mx_printcols_x(names, rows, cols, maxlen);
    } else
        mx_printrow_g(names, maxlen);
    mx_printchar('\n');
}
