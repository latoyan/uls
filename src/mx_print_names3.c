#include "uls.h"

void mx_print_names3(t_li **names, int wincol, st_fl *fl) {
    int len = 0;
    int nextlen = 0;

    for (int i = 0; names[i]; i++) {
        if (fl->G == 1)
            mx_printstr_g(names[i]);
        else if (fl->G != 1)
            mx_printstr(names[i]->name);
        len += mx_strlen(names[i]->name) + 2;
        if (names[i + 1]) {
            mx_printstr(", ");
            if (names[i + 2])
                nextlen = 3;
            else
                nextlen = 1;
            if (len + nextlen + mx_strlen(names[i + 1]->name) > wincol)
                mx_printn(&len);
        }
    }
    mx_printchar('\n');
}
