#include "uls.h"

void mx_del_files(t_li ***args, st_fl *fl) {
    t_li **dirs = NULL;
    int nDir = 0;

    mx_create_fd_op(&dirs, args);
    for (int i = 0; (*args)[i] != NULL; i++) {
        if ((*args)[i]->err == NULL) {
            if (MX_IS_DIR((*args)[i]->info.st_mode) &&
                mx_strcmp((*args)[i]->name, ".") != 0 &&
                mx_strcmp((*args)[i]->name, "..") != 0) {
                dirs[nDir++] = mx_create_file_node((*args)[i]);
                dirs[nDir] = NULL;
            }
        }
    }
    fl->files = 1;
    mx_del_liarr(args, dirs);
}
