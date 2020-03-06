#include "uls.h"

st_fl *mx_get_flags(char *argv[], int *i) {
    st_fl *fl = malloc(sizeof(st_fl));

    fl->r = 1;
    while(argv[(*i)]) {
        if (argv[(*i)][0] == '-') {
            if (argv[(*i)][1] == '-') {
                (*i)++;
                break;
            }
            if (argv[(*i)][1] == '\0')
                break;
            for (int j = 1; argv[(*i)][j]; j++)
                mx_add_flags(&fl, argv[(*i)][j]);
        }
        else
            break;
        (*i)++;
    }
    return fl;
}
