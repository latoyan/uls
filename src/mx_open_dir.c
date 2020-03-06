#include "uls.h"

void mx_open_dir(t_li ***args, st_fl *fl) {
    DIR *dptr;
    struct dirent *ds;
    int count = 0;

    for (int i = 0; (*args)[i] != NULL; i++) {
        count = mx_count_read(&(*args)[i], fl);
        if (count > 0) {
            (*args)[i]->open = malloc((count + 1) * sizeof(t_li *));
            if ((dptr = opendir((*args)[i]->path)) != NULL) {
                for (count = 0; (ds = readdir(dptr)) != NULL;)
                    if (ds->d_name[0] != '.'
                        || mx_check_a(ds->d_name, fl) == 1)
                        (*args)[i]->open[count++] =
                        mx_create_sec_node(ds->d_name, (*args)[i]->path);
                (*args)[i]->open[count] = NULL;
            closedir(dptr);
            }
        }
    }
    mx_out_put_all(args, fl);
}
