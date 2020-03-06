#include "uls.h"

t_li **mx_create_list(char **name, int count) {
    t_li **new = malloc(count * sizeof(t_li *));
    int i = 0;

    for (i = 0; name[i]; i++)
        new[i] = mx_create_li_node(name[i]);
    new[i] = NULL;
    return new;
}
