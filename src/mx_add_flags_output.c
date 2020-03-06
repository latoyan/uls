#include "uls.h"

void mx_add_flags_output(st_fl **fl, char flag) {
    mx_nulloutput(fl);
    if (flag == 'l')
        (*fl)->l = 1;
    else if (flag == 'C')
        (*fl)->C = 1;
    else if (flag == '1')
        (*fl)->force = 1;
    else if (flag == 'x')
        (*fl)->x = 1;
    else if (flag == 'm')
        (*fl)->m = 1;
    else
        mx_err_flag(fl, flag);
}
