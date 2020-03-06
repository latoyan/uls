#include "uls.h"

int main(int argc, char *argv[]) {
    int count = 1;
    st_fl *fl = mx_get_flags(argv, &count);
    t_li **args = mx_get_names(argc, argv, count);

    if (args)
        mx_opendir(&args, fl);
    mx_if_ex(fl);
    return 0;
}
