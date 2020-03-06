#include "uls.h"

void mx_del_arr_arr(t_li ***args) {
    t_li **del_arr = *args;

    for (int i = 0; del_arr[i]!= NULL; i++) {
        mx_strdel(&del_arr[i]->name);
        mx_strdel(&del_arr[i]->path);
        if (del_arr[i]->err)
            mx_strdel(&del_arr[i]->err);
        if (del_arr[i]->open != NULL)
            mx_del_arr_arr(&del_arr[i]->open);
        free(del_arr[i]);
        del_arr[i] = NULL;
    }
    free(*args);
    *args = NULL;
}
