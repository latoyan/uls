#include "uls.h"

void mx_if_ex(st_fl *fl) {
    int ex = 0;

    if (fl->ex == 1)
        ex = 1;
    free(fl);
    fl = NULL;
    exit(ex);
}
