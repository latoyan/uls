#include "uls.h"

int mx_count_read(t_li **arg, st_fl *fl) {
    int count = 0;
    t_li *args = *arg;
    DIR *dptr;
    struct dirent *ds;

    if (MX_IS_DIR(args->info.st_mode) || MX_IS_LNK(args->info.st_mode)) {
        if ((dptr = opendir(args->path)) != NULL) {
            while ((ds = readdir(dptr)) != NULL)
                if (ds->d_name[0] != '.'
                    || mx_check_a(ds->d_name, fl) == 1)
                    count++;
            closedir(dptr);
        }
        else {
            (*arg)->err = mx_strdup(strerror(errno));
            fl->ex = 1;
            return -1;
        }
    }
    return count;
}
