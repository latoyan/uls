#include "uls.h"

void mx_output_g(t_li **names, st_fl *fl) {
    int maxlen;
    struct winsize win;

    if (!names)
        return;
    maxlen = mx_max_len_n_g(names);
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    mx_print_names2(names, maxlen, win.ws_col, fl);
}
