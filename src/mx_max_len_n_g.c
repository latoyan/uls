#include "uls.h"

int mx_max_len_n_g(t_li **names) {
    int max = 0;
    int temp = 0;

    for (int i = 0; names[i]; i++) {
        temp = mx_strlen(names[i]->name);
        if (temp > max)
            max = temp;
    }
    max++;
    return max;
}
