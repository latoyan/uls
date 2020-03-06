#include "uls.h"

t_li *mx_create_li_node(char *data) {
    t_li *node = (t_li *)malloc(1 * sizeof(t_li));

    node->name = mx_strdup(data);
    node->path = mx_strdup(data);
    node->err = NULL;
    if (lstat(data, &(node->info)) == -1)
        node->err = mx_strdup(strerror(errno));	
    node->open = NULL;
    return node;
}
