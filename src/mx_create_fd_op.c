#include "uls.h"

void mx_create_fd_op(t_li ***dirs, t_li ***args) {
    int nDir = 0;

    for (int i = 0; (*args)[i] != NULL; i++)
        if ((*args)[i]->err == NULL)
            if (MX_IS_DIR((*args)[i]->info.st_mode) &&
                mx_strcmp((*args)[i]->name, ".") != 0 &&
                mx_strcmp((*args)[i]->name, "..") != 0)
                nDir++;
    if (nDir > 0)
        *dirs = malloc((nDir + 1) * sizeof(t_li *));
}
