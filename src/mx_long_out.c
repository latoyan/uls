#include "uls.h"

void mx_long_out(t_li **names, st_fl *fl, int flag) {
    t_sz *size = malloc(sizeof(t_sz));
    int blk_size = 0;
    int i = 0;

    mx_size_null(size);
    for (i = 0; names[i]; i++) {
        blk_size += names[i]->info.st_blocks;
        mx_count_size(size, names[i]);
    }
    if (flag == 1) {
        mx_printstr("total ");
        mx_printint(blk_size);
        mx_printchar('\n');
    }
    mx_check_device(names, size);
    for (i = 0; names[i]; i++)
        mx_print_all(names[i], size, fl);
    free(size);
}
