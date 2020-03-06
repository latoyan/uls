#include "uls.h"

void mx_add_flags(st_fl **fl, char flag) {
    if (flag == 'T')
        (*fl)->T = 1;
    else if (flag == 'G' && isatty(1))
        (*fl)->G = 1;
    else if (flag == 'c') {
        (*fl)->u = 0;
        (*fl)->c = 1;
    }
    else if (flag == 't')
        (*fl)->t = 1;
    else if (flag == 'u') {
        (*fl)->u = 1;
        (*fl)->c = 0;
    }
    else
        mx_add_flags_sec(fl, flag);
}
