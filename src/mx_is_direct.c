#include "uls.h"

void mx_is_direct(t_li **args, s_type *num, t_li ***files, t_li ***dirs) {
    if (!MX_IS_DIR((*args)->info.st_mode)) {
        (*files)[num->n_f++] = mx_create_file_node((*args));
        (*files)[num->n_f] = NULL;
    }
    else {
        (*dirs)[num->n_d++] = mx_create_file_node((*args));
        (*dirs)[num->n_d] = NULL;
    }
}
