#include "uls.h"

void mx_out_put_menu(t_li ***names, st_fl *fl, int flag) {
    if (**names != NULL) {
        mx_sort(&(*names), fl);
        (fl->l) ? mx_long_out(*names, fl, flag) : (void) 0;
        if (fl->C == 1 && !fl->G)
            mx_output_c(*names);
        if (fl->x == 1 && !fl->G)
            mx_output_x(*names);
        if (fl->m == 1)
            mx_output_m(*names, fl);
        if (fl->force == 1)
            mx_out_put1(*names, fl);
        if (fl->G == 1 && fl->m != 1 && fl->l != 1 && fl->force != 1)
            mx_output_g(*names, fl);
        if (fl->l != 1 && fl->C != 1 && fl->x != 1 && fl->m != 1
            && fl->force != 1 && !fl->G && !fl->g && !fl->o && isatty(1))
            mx_output_c(*names);
        if (!isatty(1) && fl->C != 1 && fl->x != 1 && fl->m != 1
            && fl->l != 1 && fl->g != 1 && fl->o != 1 && fl->force != 1)
            mx_out_put1(*names, fl);
    }
}
