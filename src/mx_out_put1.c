#include "uls.h"

void mx_out_put1(t_li **names, st_fl *fl) {
    for (int i = 0; names[i]; i++) {
        if (fl->G != 1)
            mx_printstr(names[i]->name);
        else
            mx_printstr_g(names[i]);
        mx_printchar('\n');
    }
}
