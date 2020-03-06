#include "uls.h"

void mx_output_x(t_li **names) {
    int maxlen;
    struct winsize win;

    if (!names)
        return;
    maxlen = mx_max_len_names(names);
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    if (isatty(1))
        mx_print_names4(names, maxlen, win.ws_col);
    else
        mx_print_names4(names, maxlen, 80);
}
