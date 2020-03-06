#include "uls.h"

void mx_create_fd_er(t_li ***files, t_li ***dirs,
                        t_li ***errors, t_li ***args) {
    int j = 0;
    int nDir = 0;
    int nErr = 0;

    for (int i = 0; (*args)[i] != NULL; i++)
        if ((*args)[i]->err == NULL) {
            if (!MX_IS_DIR((*args)[i]->info.st_mode) ) {
                j++;
            } else
                nDir++;
        } else
            nErr++;
    if (j > 0)
        *files = malloc((j + 1) * sizeof(t_li *));
    if (nDir > 0)
        *dirs = malloc((nDir + 1) * sizeof(t_li *));
    if (nErr > 0)
        *errors = malloc((nErr + 1) * sizeof(t_li *));
}
