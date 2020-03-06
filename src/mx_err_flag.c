#include "uls.h"

void mx_err_flag(st_fl **fl, char flag) {
    mx_printerr("uls: illegal option -- ");
    mx_printcharerr(flag);
    mx_printerr("\n");
    mx_printerr("usage: uls [-ACGRSTcglmortux1] [file ...]\n");
    free(*fl);
    fl = NULL;
    exit(1);
}
