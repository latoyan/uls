#include "uls.h"

void mx_opendir(t_li ***args, st_fl *fl) {
    t_li **files = mx_get_files(&(*args), fl);

    if (files) {
        mx_out_put_menu(&files, fl, 0);
        if (*args)
            mx_printchar('\n');
        fl->files = 1;
        mx_del_arr_arr(&files);
    }
    if (*args)
        mx_open_dir(&(*args), fl);
}
