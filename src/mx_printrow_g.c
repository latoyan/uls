#include "uls.h"

void mx_printrow_g(t_li **names, int maxlen) {
    for (int i = 0; names[i]; i++) {
        mx_printstr_g(names[i]);
        if (names[i + 1]) 
            mx_print_spaces_g(mx_strlen(names[i]->name), maxlen);
    }
}
