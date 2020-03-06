#include "uls.h"

s_type *mx_create_num() {
    s_type *num = malloc(sizeof (s_type));

    num->n_d = 0;
    num->n_e = 0;
    num->n_f = 0;
    num->i = 0;
    return num;
}
