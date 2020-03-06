#include "uls.h"

void mx_printcols_xx(t_li **names, int rows, int cols, int maxlen) {
    int j = 0;
    int tempcols = cols;

    for (int i = 0; i < rows; i++, cols += tempcols) {
        for (; names[j] && j < cols; j++) {
            mx_printstr(names[j]->name);
            if (names[j + 1] && (j != cols - 1))
                mx_print_tab(mx_strlen(names[j]->name), maxlen);
        }
        if (i != rows - 1)
            mx_printchar('\n');
    }
}
