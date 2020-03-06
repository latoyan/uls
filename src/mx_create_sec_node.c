#include "uls.h"

t_li *mx_create_sec_node(char *name, char *path) {
    t_li *node = (t_li *)malloc(1 * sizeof(t_li));

    node->name = mx_strdup(name);
    node->path = mx_strdup(path);
    mx_join(&node->path, "/");
    mx_join(&node->path, name);
    node->err = NULL;
    if (lstat(node->path, &(node->info)) == -1)
        node->err = mx_strdup(strerror(errno));
    node->open = NULL;
    return node;
}
