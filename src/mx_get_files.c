#include "uls.h"

t_li **mx_get_files(t_li ***args, st_fl *fl) {
    t_li **files = NULL;
    t_li **dirs = NULL;
    t_li **errors = NULL;
    s_type *num = mx_create_num();

    mx_create_fd_er(&files, &dirs, &errors, args);
    for (; (*args)[num->i] != NULL; num->i++) {
        if ((*args)[num->i]->err == NULL)
            mx_is_direct(&(*args)[num->i], num, &files, &dirs);
        else {
            errors[num->n_e++] = mx_create_file_node((*args)[num->i]);
            errors[num->n_e] = NULL;
        }
    }
    if (num->n_d > 1)
        fl->files = 1;
    mx_del_liarr(args, dirs);
    mx_out_err(&errors, fl);
    free(num);
    return files;
}
