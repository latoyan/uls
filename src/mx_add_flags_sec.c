#include "uls.h"

void mx_add_flags_sec(st_fl **fl, char flag) {
    if (flag == 'S')
        (*fl)->S = 1;
    else if (flag == 'r' && (*fl)->r != -1)
        (*fl)->r = 0;
    else if (flag == 'G' && !isatty(1))
        (*fl)->G = 0;
    else if (flag == 'R')
        (*fl)->R = 1;
    else if (flag == 'A')
        (*fl)->A = 1;
    else if (flag == 'g') {
        (*fl)->g = 1;
        (*fl)->l = 1;
    }
    else if (flag == 'o') {
        (*fl)->o = 1;
        (*fl)->l = 1;
    }
    else
        mx_add_flags_output(fl, flag);
}
