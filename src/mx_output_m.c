#include "uls.h"

void mx_output_m(t_li **names, st_fl *fl) {
    struct winsize win;

    if (!names)
        return;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    if (isatty(1))
        mx_print_names3(names, win.ws_col, fl);
    else
        mx_print_names3(names, 80, fl);
}
