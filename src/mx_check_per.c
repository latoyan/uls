#include "uls.h"

char mx_check_per(t_li *print) {
    if (MX_IS_DIR(print->info.st_mode))
        return 'd';
    if (MX_IS_LNK(print->info.st_mode))
        return 'l';
    if (MX_IS_BLK(print->info.st_mode))
        return 'b';
    if (MX_IS_CHR(print->info.st_mode))
        return 'c';
    if (MX_IS_FIFO(print->info.st_mode))
        return 'p';
    if (MX_IS_SOCK(print->info.st_mode))
        return 's';
    if (MX_IS_WHT(print->info.st_mode))
        return 'w';
    return '-';
}
