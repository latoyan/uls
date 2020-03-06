#include "uls.h"

t_li **mx_get_names(int argc, char **argv, int i) {
    int count = 0;
    char **name = mx_names(argc, argv, i, &count);
    t_li **args = mx_create_list(name, count);

    mx_del_strarr(&name);
    return args;
}
