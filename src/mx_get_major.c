#include "uls.h"

char *mx_get_major(t_li *print) {
    return mx_itoa((int)(((unsigned int)print->info.st_rdev >> 24) & 0xff));
}
